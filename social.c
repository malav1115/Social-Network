#include "social.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 50
struct Node *allNodes[MAX_SIZE];
int nsize = 0;
char date_string[20];
struct individual *allIndividual[MAX_SIZE];
int nIndividual = 0;
struct Business *allBusiness[MAX_SIZE];
int nBusiness = 0;
struct Organisation *allOrganisation[MAX_SIZE];
int nOrganisation = 0;
struct Group *allGroups[MAX_SIZE];
int nGroups = 0;

int main()
{
    int n;
    printf("Enter 1 to Create a Node : ");
    scanf("%d", &n);
    if (n == 1)
    {
        while (1)
        {
            printf("Enter the type of Node, you want to create (0-INDIVIDUAL),(1-BUSINESS),(2-GROUP),(3-ORGANISATION):- ");
            int type;
            scanf("%d", &type);
            if (type == 0)
            {
                struct individual *new_individual = CreateIndividual();
                if (new_individual != NULL)
                    printf("--Node Created--\n");
            }
            else if (type == 1)
            {
                struct Business *new_business = CreateBusiness();
                if (new_business != NULL)
                    printf("--Node Created--\n");
            }
            else if (type == 2)
            {
                struct Group *new_grp = CreateGroup();
                if (new_grp != NULL)
                    printf("--Node Created--\n");
            }
            else if (type == 3)
            {
                struct Organisation *new_org = CreateOrganisation();
                if (new_org != NULL)
                    printf("--Node Created--\n");
            }
            else
            {
                printf("Wrong Input!!\n");
            }
            printf("Enter 1 to Create another Node : ");
            int k;
            scanf("%d", &k);
            if (k != 1)
                break;
        }
        printf("Enter 1 to printf all nodes you have created:- ");
        int a;
        scanf("%d", &a);
        if (a == 1)
        {
            PrintAllNodes();
        }
        printf("Enter 1 to Links two Nodes: ");
        int c;
        scanf("%d", &c);
        if (c == 1)
        {
            while (1)
            {
                printf("Again Enter 1 to Link two Nodes: ");
                int d;
                scanf("%d", &d);
                if (d == 1)
                {
                    printf("Enter the ID of the Node you want to Link: ");
                    int id1;
                    scanf("%d", &id1);
                    struct Node *node1 = SearchbyId(id1);
                    if (node1 == NULL)
                    {
                        printf("Node not Found!!\n");
                        continue;
                    }
                    printf("Enter the ID of the Node you want to Link: ");
                    int id2;
                    scanf("%d", &id2);
                    struct Node *node2 = SearchbyId(id2);
                    if (node2 == NULL)
                    {
                        printf("Node not Found!!\n");
                        continue;
                    }
                    if (node1->type == 0 && node2->type == 1)
                    {
                        struct individual *temp1 = SearchIndividual(node1->id);
                        struct Business *temp2 = SearchBusiness(node2->id);
                        Add_Owner_to_Business(temp2, temp1);
                        printf("Linked!!\n");
                    }
                    else if (node1->type == 0 && node2->type == 2)
                    {
                        struct individual *temp1 = SearchIndividual(node1->id);
                        struct Group *temp2 = SearchGroup(node2->id);
                        Add_Member_to_Group(temp2, temp1);
                        printf("Linked!!\n");
                    }
                    else if (node1->type == 0 && node2->type == 3)
                    {
                        struct individual *temp1 = SearchIndividual(node1->id);
                        struct Organisation *temp2 = SearchOrganisation(node2->id);
                        Add_Member_to_Organisation(temp2, temp1);
                        printf("Linked!!\n");
                    }
                    else if (node1->type == 1 && node2->type == 0)
                    {
                        struct individual *temp1 = SearchIndividual(node2->id);
                        struct Business *temp2 = SearchBusiness(node1->id);
                        Add_Constumers_to_Business(temp2, temp1);
                        printf("Linked!!\n");
                    }
                    else if (node1->type == 1 && node2->type == 2)
                    {
                        struct Business *temp1 = SearchBusiness(node1->id);
                        struct Group *temp2 = SearchGroup(node2->id);
                        Add_Group_to_Business(temp1, temp2);
                        printf("Linked!!\n");
                    }
                    else if (node1->type == 2 && node2->type == 1)
                    {
                        struct Business *temp1 = SearchBusiness(node2->id);
                        struct Group *temp2 = SearchGroup(node1->id);
                        Add_Group_to_Business(temp1, temp2);
                        printf("Linked!!\n");
                    }
                    else
                    {
                        printf("They can't be linked!!\n");
                    }
                }
                else
                {
                    break;
                }
            }
        }
        printf("Enter 1 to search for any Node: ");
        int e;
        scanf("%d", &e);
        if (e == 1)
        {
            while (1)
            {
                printf("Again Enter 1 to search for any Node: ");
                int f;
                scanf("%d", &f);
                if (f == 1)
                {
                    printf("Enter 1 to search by ID, 2 to search by Name, 3 to search by Birthday: ");
                    int g;
                    scanf("%d", &g);
                    if (g == 1)
                    {
                        printf("Enter the ID of the Node you want to search: ");
                        int id;
                        scanf("%d", &id);
                        struct Node *node = SearchbyId(id);
                        if (node == NULL)
                            printf("Node not Found!!\n");
                        else
                        {
                            PrintNode(node);
                        }
                    }
                    else if (g == 2)
                    {
                        printf("Enter the Name of the Node you want to search: ");
                        char name[MAX_SIZE];
                        fgets(name, MAX_SIZE, stdin); // this fgets is just to clear the buffer
                        scanf("%[^\n]%*c", name);
                        struct Node *node = SearchbyName(name);
                        if (node == NULL)
                            printf("Node not Found!!\n");
                        else
                        {
                            PrintNode(node);
                        }
                    }
                    else if (g == 3)
                    {
                        printf("Enter the Birthday of the Node you want to search: ");
                        char birthday[MAX_SIZE];
                        fgets(birthday, MAX_SIZE, stdin); // this fgets is just to clear the buffer
                        scanf("%[^\n]%*c", birthday);
                        struct Node *node = SearchbyBirthday(birthday);
                        if (node == NULL)
                            printf("Node not Found!!\n");
                        else
                        {
                            PrintNode(node);
                        }
                    }
                    else
                    {
                        printf("Wrong Input!!\n");
                    }
                }
                else
                {
                    break;
                }
            }
        }
        printf("Enter 1 to Printf 1-hope of a Node: ");
        int b;
        scanf("%d", &b);
        if (b == 1)
        {
            printf("Enter ID of the name: ");
            int id;
            scanf("%d", &id);
            struct Node *node = SearchbyId(id);
            if (node == NULL)
                printf("Node not Found!!\n");
            else
            {
                PrintNodesbyNode(node);
            }
        }
        printf("Enter 1 to Create a Post Content to a Node: ");
        int h;
        scanf("%d", &h);
        if (h == 1)
        {
            while (1)
            {
                printf("AGain Enter 1 to Create a Post Content to a Node: ");
                int k;
                scanf("%d", &k);
                if (k == 1)
                {
                    printf("Enter the ID of the Node you want to Create a Post Content: ");
                    int id;
                    scanf("%d", &id);
                    struct Node *node = SearchbyId(id);
                    if (node == NULL)
                        printf("Node not Found!!\n");
                    else
                    {
                        Create_Post_Content(node);
                    }
                }
                else
                {
                    break;
                }
            }
        }
        printf("Enter 1 to Printf all the Content of a Node: ");
        int i;
        scanf("%d", &i);
        if (i == 1)
        {
            printf("Enter the ID of the Node you want to Printf all the Content: ");
            int id;
            scanf("%d", &id);
            struct Node *node = SearchbyId(id);
            if (node == NULL)
                printf("Node not Found!!\n");
            else
            {
                PrintAllContentofaNode(node);
            }
        }
        printf("Enter 1 to Search for a Content: ");
        int j;
        scanf("%d", &j);
        if (j == 1)
        {
            Search_for_content();
        }
        printf("Enter 1 to Display content of connected node to individual: - ");
        int l;
        scanf("%d", &l);
        if (l == 1)
        {
            printf("Enter the ID of the Individual: ");
            int id;
            scanf("%d", &id);
            struct individual *Individual = SearchIndividual(id);
            if (Individual == NULL)
                printf("Individual not Found!!\n");
            else
            {
                Dipslay_Content_ofconneted_Individaul(Individual);
            }
        }
        printf("Enter 1 to delete any Node: ");
        int m;
        scanf("%d", &m);
        if (m == 1)
        {
            while (1)
            {
                printf("Again Enter 1 to delete any Node: ");
                int n;
                scanf("%d", &n);
                if (n == 1)
                {
                    printf("Enter 1 to delete by ID, 2 to delete by Name, 3 to delete by Birthday: ");
                    int o;
                    scanf("%d", &o);
                    if (o == 1)
                    {
                        printf("Enter the ID of the Node you want to delete: ");
                        int id;
                        scanf("%d", &id);
                        struct Node *node = SearchbyId(id);
                        if (node == NULL)
                            printf("Node not Found!!\n");
                        else
                        {
                            DeleteNode(node);
                            printf("Node Deleted!!\n");
                        }
                    }
                    else if (o == 2)
                    {
                        printf("Enter the Name of the Node you want to delete: ");
                        char name[MAX_SIZE];
                        fgets(name, MAX_SIZE, stdin); // this fgets is just to clear the buffer
                        scanf("%[^\n]%*c", name);
                        struct Node *node = SearchbyName(name);
                        if (node == NULL)
                            printf("Node not Found!!\n");
                        else
                        {
                            DeleteNode(node);
                            printf("Node Deleted!!\n");
                        }
                    }
                    else if (o == 3)
                    {
                        printf("Enter the Birthday of the Node you want to delete: ");
                        char birthday[MAX_SIZE];
                        fgets(birthday, MAX_SIZE, stdin); // this fgets is just to clear the buffer
                        scanf("%[^\n]%*c", birthday);
                        struct Node *node = SearchbyBirthday(birthday);
                        if (node == NULL)
                            printf("Node not Found!!\n");
                        else
                        {
                            DeleteNode(node);
                            printf("Node Deleted!!\n");
                        }
                    }
                    else
                    {
                        printf("Wrong Input!!\n");
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }
    DeleteAll();
}

// todays date
char *today_date()
{
    time_t t;
    struct tm *info;
    time(&t);
    info = localtime(&t);

    // Formatting the date as "DD/MM/YYYY" for India
    strftime(date_string, sizeof(date_string), "%d/%m/%Y", info);

    return date_string;
}

// Function for Printing all type of NODES

// Node printing funciton
void PrintNode(struct Node *node)
{
    printf("Id: %d | Name: %s | Creation Date: %s | Type: %d\n", node->id, node->name, node->date, node->type);
}

// Individual Details Printing fuction
void PrintIndividual(struct individual *Individual)
{
    printf("Id: %d\tName: %s\tCreation Date: %s\tBirthday: %s\n", Individual->node->id, Individual->node->name, Individual->node->date, Individual->birthday);
}

// Print all the Nodes exist in social network
void PrintAllNodes()
{
    printf("All the Nodes exist in SOCIAL NETWORK\n");
    for (int i = 0; i < nsize; i++)
    {
        PrintNode(allNodes[i]);
    }
}

// Print Business Details
void PrintBusiness(struct Business *business)
{
    printf("ID: %d\tName: %s\tLocation: (%lf, %lf)\n", business->node->id, business->node->name, business->x_cordinate, business->y_cordinate);
}

// Print Group Detail
void PrintGroup(struct Group *group)
{
    printf("ID: %d\tName: %s\n", group->node->id, group->node->name);
}

// Print Organisation Details
void PrintOrganisation(struct Organisation *orgi)
{
    printf("ID: %d\tName: %s\tLocation: (%lf,%lf)\n", orgi->node->id, orgi->node->name, orgi->x_cordinate, orgi->y_cordinate);
}

// Creation Functions of all type of Nodes --

/*-- Points -1 Solution : Created Function for Creating and Deleting All typed of NODES::: */
// Create Node
struct Node *CreateNode(Nodetype type)
{
    int id;
    char name[MAX_SIZE];

    printf("Enter ID for the Node : ");
    scanf("%d", &id);
    struct Node *local = SearchbyId(id);
    if (local != NULL)
        printf("This ID already Exist, Try Again!!-\n");
    else
    {

        printf("Enter the name of the Node: ");
        fgets(name, MAX_SIZE, stdin); // this fgets is just to clear the buffer
        scanf("%[^\n]%*c", name);

        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->id = id;
        new_node->name = strdup(name);
        new_node->date = strdup(today_date());
        new_node->type = type;
        // new_node->links = NULL;
        new_node->numlinks = 0;
        // new_node->content = NULL;
        new_node->numcontent = 0;

        allNodes[nsize] = new_node;
        nsize++;
        return new_node;
    }
    return NULL;
}

// Create Individual
struct individual *CreateIndividual()
{

    struct Node *new_node = CreateNode(INDIVIDUAL);
    if (new_node != NULL)
    {
        char birthday[MAX_SIZE];
        printf("Enter Bithday of Individual: ");
        scanf("%[^\n]%*c", birthday);
        struct individual *new_individual = (struct individual *)malloc(sizeof(struct individual));
        new_individual->node = new_node;
        new_individual->birthday = strdup(birthday);
        // new_individual->blist = NULL;
        new_individual->nblist = 0;
        // new_individual->Glist = NULL;
        new_individual->nGlist = 0;
        // new_individual->Olist = NULL;
        new_individual->nOlist = 0;
        allIndividual[nIndividual++] = new_individual;
        return new_individual;
    }
    return NULL;
}

// Create Business
struct Business *CreateBusiness()
{
    double x, y;
    struct Node *new_node = CreateNode(BUSINESS);
    if (new_node != NULL)
    {
        printf("Enter the Location(x,y): ");
        scanf("%lf%lf", &x, &y);
        struct Business *new_business = (struct Business *)malloc(sizeof(struct Business));
        new_business->node = new_node;
        new_business->x_cordinate = x;
        new_business->y_cordinate = y;
        // new_business->owner = NULL;
        new_business->nowner = 0;
        // new_business->customer = NULL;
        new_business->nconstomer = 0;
        // new_business->Glist = NULL;
        new_business->nGlist = 0;
        allBusiness[nBusiness++] = new_business;
        return new_business;
    }
    return NULL;
}

// Create Group
struct Group *CreateGroup()
{
    struct Node *new_node = CreateNode(GROUP);
    if (new_node != NULL)
    {
        struct Group *new_group = (struct Group *)malloc(sizeof(struct Group));
        new_group->node = new_node;
        // new_group->members = NULL;
        new_group->nmember = 0;
        // new_group->Blist = NULL;
        new_group->nBlist = 0;
        allGroups[nGroups++] = new_group;
        return new_group;
    }
    return NULL;
}

// Create Organisation
struct Organisation *CreateOrganisation()
{
    struct Node *new_node = CreateNode(ORGANISATION);
    if (new_node != NULL)
    {
        double x, y;
        struct Organisation *new_org = (struct Organisation *)malloc(sizeof(struct Organisation));
        printf("Enter the Location(x,y): ");
        scanf("%lf%lf", &x, &y);
        new_org->node = new_node;
        new_org->x_cordinate = x;
        new_org->y_cordinate = y;
        // new_org->members = NULL;
        new_org->nmembers = 0;
        allOrganisation[nOrganisation++] = new_org;
        return new_org;
    }
    return NULL;
}

// All Delete Function

// Delete a Node which delete node from all the places where it present
void DeleteNode(struct Node *node)
{
    for (int i = 0; i < nsize; i++)
    {
        if (allNodes[i] == node)
        {
            for (int j = i; j < nsize - 1; j++)
            {
                allNodes[j] = allNodes[j + 1];
            }
            nsize--;
            break;
        }
    }
    if (node->type == 0)
    {
        for (int i = 0; i < nIndividual; i++)
        {
            if (allIndividual[i]->node == node)
            {
                for (int j = i; j < nIndividual - 1; j++)
                {
                    allIndividual[j] = allIndividual[j + 1];
                }
                nIndividual--;
                break;
            }
        }
    }
    else if (node->type == 1)
    {
        for (int i = 0; i < nBusiness; i++)
        {
            if (allBusiness[i]->node == node)
            {
                for (int j = i; j < nBusiness - 1; j++)
                {
                    allBusiness[j] = allBusiness[j + 1];
                }
                nBusiness--;
                break;
            }
        }
    }
    else if (node->type == 2)
    {
        for (int i = 0; i < nGroups; i++)
        {
            if (allGroups[i]->node == node)
            {
                for (int j = i; j < nGroups - 1; j++)
                {
                    allGroups[j] = allGroups[j + 1];
                }
                nGroups--;
                break;
            }
        }
    }
    else if (node->type == 3)
    {
        for (int i = 0; i < nOrganisation; i++)
        {
            if (allOrganisation[i]->node == node)
            {
                for (int j = i; j < nOrganisation - 1; j++)
                {
                    allOrganisation[j] = allOrganisation[j + 1];
                }
                nOrganisation--;
                break;
            }
        }
    }
    free(node);
}
// Delete a Individual which delete node from all the places where it present
void DeleteIndividual(struct individual *Individual)
{
    DeleteNode(Individual->node);
    free(Individual);
}

// Delete a Business
void DeleteBusiness(struct Business *business)
{
    DeleteNode(business->node);
    free(business);
}

// Delete a Organisation
void DeleteOrganisation(struct Organisation *new_org)
{
    DeleteNode(new_org->node);
    free(new_org);
}

// Delete a Group
void DeleteGroup(struct Group *new_grp)
{
    DeleteNode(new_grp->node);
    free(new_grp);
}

// Delete the whole social network
void DeleteAll()
{
    for (int i = 0; i < nsize; i++)
    {
        free(allNodes[i]);
    }
    for (int i = 0; i < nIndividual; i++)
    {
        free(allIndividual[i]);
    }
    for (int i = 0; i < nBusiness; i++)
    {
        free(allBusiness[i]);
    }
    for (int i = 0; i < nOrganisation; i++)
    {
        free(allOrganisation[i]);
    }
    for (int i = 0; i < nGroups; i++)
    {
        free(allGroups[i]);
    }
    nsize = 0;
    nIndividual = 0;
    nBusiness = 0;
    nOrganisation = 0;
    nGroups = 0;
}
/* Points 1 solutions Ends HEre:::*/

/* Points 2 Solution: Created the functions to Search for Node by id, Name, Birthday: These Function will return matching Node that can be printed by PrintNode() Function  */

// ALL searching functions

// Search a Node by its ID
struct Node *SearchbyId(int id)
{
    for (int i = 0; i < nsize; i++)
    {
        if (allNodes[i]->id == id)
            return allNodes[i];
    }
    return NULL;
}

// Search a NODe by its name
struct Node *SearchbyName(char *name)
{
    for (int i = 0; i < nsize; i++)
    {
        if (strcmp(allNodes[i]->name, name) == 0)
            return allNodes[i];
    }
    return NULL;
}

// Search BY Birthday
struct Node *SearchbyBirthday(char *birthday)
{
    for (int i = 0; i < nIndividual; i++)
    {
        if (strcmp(allIndividual[i]->birthday, birthday)==0)
            return allIndividual[i]->node;
    }
    return NULL;
}

// Some Required Searching Function
struct individual *SearchIndividual(int id)
{
    for (int i = 0; i < nIndividual; i++)
    {
        if (allIndividual[i]->node->id == id)
            return allIndividual[i];
    }
    return NULL;
}
struct Business *SearchBusiness(int id)
{
    for (int i = 0; i < nBusiness; i++)
    {
        if (allBusiness[i]->node->id == id)
            return allBusiness[i];
    }
    return NULL;
}
struct Organisation *SearchOrganisation(int id)
{
    for (int i = 0; i < nOrganisation; i++)
    {
        if (allOrganisation[i]->node->id == id)
            return allOrganisation[i];
    }
    return NULL;
}
struct Group *SearchGroup(int id)
{
    for (int i = 0; i < nGroups; i++)
    {
        if (allGroups[i]->node->id == id)
            return allGroups[i];
    }
    return NULL;
}

// Point 2 ENds HEre

// Points 3 Solution: Created Some Helper function which will help to print the 1 hop of any node. Then Created Functions for PRinting one hope

// Print all connected Nodes of a given Node
void PrintNodesbyNode(struct Node *node)
{
    if (node->numlinks == 0)
    {
        printf("This Node DOesn't content any LInks.\n");
        return;
    }
    printf("All the Nodes Conneted to Given Node : \n");
    for (int i = 0; i < node->numlinks; i++)
    {
        PrintNode(node->links[i]);
    }
    printf("\n");
}

// Print Business connected to given Individual
void PrintBusinessofIndividual(struct individual *Individual)
{
    printf("All the Business connected to given Individual: \n");
    for (int i = 0; i < Individual->nblist; i++)
    {
        PrintBusiness(Individual->blist[i]);
    }
    printf("\n");
}

// Print all Groups in which individual joined
void PrintGroupsofIndividual(struct individual *Individual)
{
    printf("All the Groups connected to given Individual: \n");
    for (int i = 0; i < Individual->nGlist; i++)
    {
        PrintGroup(Individual->Glist[i]);
    }
    printf("\n");
}

// Print all Organisations in which individual joined
void PrintOrganisationofIndividual(struct individual *Individual)
{
    printf("All Organisations connected to given Individual: \n");
    for (int i = 0; i < Individual->nGlist; i++)
    {
        PrintOrganisation(Individual->Olist[i]);
    }
    printf("\n");
}

// Print all owner of a Business
void PrintOwnersofBusiness(struct Business *business)
{
    printf("All Owners of The Business: \n");
    for (int i = 0; i < business->nowner; i++)
    {
        PrintIndividual(business->owner[i]);
    }
    printf("\n");
}

// Print all constumers of a Business
void PrintCostumersofBusiness(struct Business *business)
{
    printf("All constumers of The Business: \n");
    for (int i = 0; i < business->nconstomer; i++)
    {
        PrintIndividual(business->customer[i]);
    }
    printf("\n");
}

// Print all Groups of a Business
void PrintGroupsofBusiness(struct Business *business)
{
    printf("All Groups in which Business is a Member: \n");
    for (int i = 0; i < business->nGlist; i++)
    {
        PrintGroup(business->Glist[i]);
    }
    printf("\n");
}

// Print members of a Organisation
void PrintMembersofOrganisation(struct Organisation *new_Organisation)
{
    printf("All Members of the Orgnisation: \n");
    for (int i = 0; i < new_Organisation->nmembers; i++)
    {
        PrintIndividual(new_Organisation->members[i]);
    }
    printf("\n");
}

// Print members of a Group
void PrintMembersofGroup(struct Group *new_grp)
{
    printf("All Members of the Group: \n");
    for (int i = 0; i < new_grp->nmember; i++)
    {
        PrintIndividual(new_grp->members[i]);
    }
    printf("\n");
}

// Print Business who joined this Group
void PrintBusinessofGroup(struct Group *new_grp)
{
    printf("All Business who joined The Group: \n");
    for (int i = 0; i < new_grp->nBlist; i++)
    {
        PrintBusiness(new_grp->Blist[i]);
    }
    printf("\n");
}

// Printing 1-hop of Individual

void Print_1_hop_for_indiviual(struct individual *Individual)
{
    PrintBusinessofIndividual(Individual);
    PrintGroupsofIndividual(Individual);
    PrintOrganisationofIndividual(Individual);
}

// Printing 1-hop for Business
void Print_1_hop_for_Business(struct Business *business)
{
    PrintOwnersofBusiness(business);
    PrintCostumersofBusiness(business);
    PrintGroupsofBusiness(business);
}

// Printing 1-hop for Group
void Print_1_hop_for_Group(struct Group *grp)
{
    PrintMembersofGroup(grp);
    PrintBusinessofGroup(grp);
}

void Print_1_hop_for_Organisation(struct Organisation *org)
{
    PrintMembersofOrganisation(org);
}

// Points 3 Solution : Printing one hope code ends here --

// Point 4 Solution : Created Function to Create and Post the Content for given NODE:::

// Functoin to check for the duplicate content
bool CheckDuplicateContent(struct Node *node, char *s)
{
    for (int i = 0; i < node->numcontent; i++)
    {
        if (strcmp(node->content[i], s) == 0)
        {
            return false;
        }
    }
    return true;
}

// Create content fucntion
void Create_Post_Content(struct Node *node)
{
    char s[MAX_CONTENT_SIZE];
    printf("Write Content you want to post: ");
    fgets(s, MAX_CONTENT_SIZE, stdin); // this fgets is just to clear the buffer
    scanf("%[^\n]%*c", s);
    // check is content already exists
    if (CheckDuplicateContent(node, s))
        node->content[node->numcontent++] = strdup(s);
}

// Printf all the posts of a node
void PrintAllContentofaNode(struct Node *node)
{
    for (int i = 0; i < node->numcontent; i++)
    {
        printf("Post[%d]: %s\n", i + 1, node->content[i]);
    }
}

// Point 4 Code ends HERE:::

// Point 5 Solution: Created funtion which will search for the provided content and return the node where it belongs to :::

// Search for the content
struct Node *Search_for_content_helper()
{
    char s[MAX_CONTENT_SIZE];
    printf("Enter the Content You want to Search for :- ");
    fgets(s, MAX_CONTENT_SIZE, stdin); // this fgets is just to clear the buffer
    scanf("%[^\n]%*c", s);
    for (int i = 0; i < nsize; i++)
    {
        for (int j = 0; j < allNodes[i]->numcontent; i++)
        {
            if (strcmp(allNodes[i]->content[j], s) == 0)
                return allNodes[i];
        }
    }
    return NULL;
}

void Search_for_content()
{
    struct Node *new = Search_for_content_helper();
    if (new == NULL)
        printf("Not Found!!\n");
    else
    {
        printf("Detais of the Node which Content belongs to : ");
        PrintNode(new);
    }
}
// Points 5 Ends Here::::

// Point 6 Solution : Created Function to Displaying the content of content posted by individuals linked to a given individual
void Dipslay_Content_ofconneted_Individaul(struct individual *Individual)
{
    printf("Displaying All the Contents of linked Individual to Provided Individual Posted: ");
    for (int i = 0; i < Individual->node->numlinks; i++)
    {
        if (Individual->node->links[i]->type == 0)
        {
            PrintAllContentofaNode(Individual->node->links[i]);
        }
    }
}
// Point 6 Code Ends Here:::

// Code for Linking Different type of Nodes

// Link owner to Business
void Add_Owner_to_Business(struct Business *new_business, struct individual *new_indi)
{
    new_business->owner[new_business->nowner++] = new_indi;
    new_indi->blist[new_indi->nblist++] = new_business;
    new_business->node->links[new_business->node->numlinks++] = new_indi->node;
    new_indi->node->links[new_indi->node->numlinks++] = new_business->node;
}

// Link constumers to Business
void Add_Constumers_to_Business(struct Business *new_business, struct individual *new_indi)
{
    new_business->customer[new_business->nconstomer++] = new_indi;
    new_indi->blist[new_indi->nblist++] = new_business;
    new_business->node->links[new_business->node->numlinks++] = new_indi->node;
    new_indi->node->links[new_indi->node->numlinks++] = new_business->node;
}

// Link Group to Business
void Add_Group_to_Business(struct Business *new_business, struct Group *new_grp)
{
    new_business->Glist[new_business->nGlist++] = new_grp;
    new_grp->Blist[new_grp->nBlist++] = new_business;
    new_business->node->links[new_business->node->numlinks++] = new_grp->node;
    new_grp->node->links[new_grp->node->numlinks++] = new_business->node;
}

// Link Individual to Group
void Add_Member_to_Group(struct Group *new_grp, struct individual *new_indi)
{
    new_grp->members[new_grp->nmember++] = new_indi;
    new_indi->Glist[new_indi->nGlist++] = new_grp;
    new_grp->node->links[new_grp->node->numlinks++] = new_indi->node;
    new_indi->node->links[new_indi->node->numlinks++] = new_grp->node;
}

// Link Individual to Organisation
void Add_Member_to_Organisation(struct Organisation *new_org, struct individual *new_indi)
{
    new_org->members[new_org->nmembers++] = new_indi;
    new_indi->Olist[new_indi->nOlist++] = new_org;
    new_org->node->links[new_org->node->numlinks++] = new_indi->node;
    new_indi->node->links[new_indi->node->numlinks++] = new_org->node;
}

// Linking Code Ends Here :::
// Assignment End HEre!!