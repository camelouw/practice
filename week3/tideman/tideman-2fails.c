#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
    int win_amount;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2]; 

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool checkcycle(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

/*  Update ranks given a new vote
    Vote 1
    rank = 0 -- A [index 0]
    rank = 1 -- C [index 2]
    rank = 2 -- B [index 1]
    ranks[0, 2, 1]
*/
bool vote(int rank, string name, int ranks[])
{
    // TODO:
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i; 
            return true;// if true vote is valid (vote name matches a given candidate name)
        }
    }
    return false; // false return results in "invalid vote"
}

/*  Update preferences given one voter's ranks
    [0, 2, 1] - array, and itteration to achieve
     i  j
     i     j
        i  j
*/
void record_preferences(int ranks[])
{
/*  TODO: tally up the preferences from ranks[] and add to preference[][]
    structure of input for class example 
    i j j 
    i j j
    i j j 
    i j j

    Output expected for class example
    pref[0][1] = 3
    pref[0][2] = 3
    pref[1][0] = 1
    pref[1][2] = 1
    pref[2][0] = 1
    pref[2][1] = 3
*/
    for (int i = 0; i < candidate_count; i++) 
    {
        for(int j = i + 1; j < candidate_count; j++) 
        {
            preferences[ranks[i]][ranks[j]]++; //increment based on index
        }
    }   
    return;
}

void add_pairs(void)
{
/*  TODO: Record pairs() where candidate i wins over j or where j wins over i
    i               vs. j                   winners         = // should be candidate index
    pref[0][1] = 3  vs. pref[1][0] = 1      pairs[0].winner = [0] (i)                       A-b
    pref[0][2] = 3  vs. pref[2][0] = 1      pairs[1].winner = [0] (i)                       A-c
    pref[1][2] = 1  vs. pref[2][1] = 3      pairs[2].winner = [2] (j)                       C-b

    ties do no get inserted to pairs[]
*/
    for (int i = 0; i < MAX; i++) 
    {
        for (int j = i + 1; j < MAX; j++) 
        {      
            //this is when i is preferred and we update i as winner
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count++].loser = j;//update global variable
            }
            //if j wins they are the winner in pairs
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count++].loser = i;//update global variable
            }
        }
        
    }
    return;
}

/* Sort pairs in decreasing order by strength of victory 
class example:                  winners         amount-by
pairs[0].winner = [0] (i)       A-b             3-1 = 2
pairs[1].winner = [0] (i)       A-c             3-1 = 2
pairs[2].winner = [2] (j)       C-b             3-1 = 2
 
Method - Selection Sort steps
a: work out win score
b: save win score under pairs[].win_amount
1: iterate through pairs[] starting from [0], store biggest int in a temp var
2: swap temp var with pairs[0]
3: iterate through pairs[] starting from [1], store biggest int in a temp var
4: swap temp var with pairs[1]
5: iterate through pairs[] starting from [2], store biggest int in a temp var
6: swap temp var with pairs[2]
*/
void sort_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = i + 1; j < pair_count; j++)
        {
            pairs[i].win_amount = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[j].winner][pairs[j].loser]; 
            pairs[j].win_amount = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[i].winner][pairs[i].loser]; 

            if (pairs[i].win_amount < pairs[j].win_amount)
            {   // this will run from [i,j,j,j,j] till the highest value replaces i
                // [x,i,j,j,j]
                // [x,x,i,j,j]
                pair temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;
            }
        }
    }
    return;
}

/* TODO: Lock pairs into the candidate graph in order, without creating cycles. 
A-b-> A-c-> C-b

1: iterate through pairs (winners and losers)
2: if there is no cycle, add to locked[i][j] (true)
3: if there is a cycle, do not create cycle

"You may assume there will not be more than one source."

Output -> locked[][] - true and false 2D array

Lock in (my best guess)
locked[pairs[0].winner][pairs[0].loser] = true/false
locked[pairs[1].winner][pairs[1].loser] = true/false
locked[pairs[2].winner][pairs[2].loser] = true/false

*/

// is loser in pairs locked winning in any previously locked?
// if no cycle (loser != previous winner), continue.
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++) 
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
        
        for (int j = 0; j < pair_count; j++)
        {
            if (locked[pairs[i].loser][pairs[j].winner] == true)
            {
                locked[pairs[i].winner][pairs[i].loser] = false;
            }
        }
    }          
    return;
}

// Print the winner of the election
void print_winner(void)
{
    string candidate_winner;
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == true)
            {
                candidate_winner = candidates[pairs[i].winner];
            }
        }
    }
    printf("%s\n", candidate_winner);
    return;
}
/*
bool checkcycle(void)
{
    for (int i = 0; i < pair_count; i++s) 
    {
        for (int j = i + 1; j < pair_count; j++) 
        {
            // check for cycle
            if (pairs[i].loser == pairs[j].winner)
            {
                return true;
            }
        }
    }
    return false;
}
*/