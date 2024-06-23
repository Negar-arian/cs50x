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
bool check_cycle(int winner,int loser);

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

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for(int i = 0;i < candidate_count;i++)
    {
        if(strcmp(name ,candidates[i]) == 0)
        {
            ranks[rank] = candidate;

            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for(int i = 0;i < candidate_count;i++)
    {
        for(int j = 0 < candidate_count;j++)
        {
            if(i != j+1)
            {
               preferences[ranks[i]][ranks[j+1]] ++;
            }
            else
            {
                preferances[ranks[i]][ranks[j+1]] = 0;
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for(int i = 0;i < candidate_count;i++)
    {
        for(int j = 0;j < candidate;j++)
        {
            if(preferances[i][j+1] > preferances[j+1][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    for(int i = 0;i < pair_count;i++)
    {
        for(int j = i+1 ; j < pair_count - i -1; j++)
        {
            int i1 = pairs[j].winner;
            int j1 = pairs[j].loser;

            int stpair1 = preferences[i1][j1] - preferences[j1][i1];

            int i2 = pairs[j+1].winner;
            int j2 = pairs[j+1].loser;

            int stpair2 = preferences[i2][j2] - preferences[j2][i2];

            if(stpair1 > stpair2)
            {
                temp = pairs[j];
                pairs[j] = pairs[j+1];
                pairs[j+1] = temp;
            }



        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    int winner;
    int loser;
    for(int i = 0;i < pair_count; i++)
    {
        winner = pairs[i].winner;
        loser = pairs[i].loser;

        if(!=check_cycle(winner,loser))
        {
            locked[winner][loser] = true;
        }
    }
    return;
}

bool check_cycle(int winner,int loser)
{
      if(loser == winner)
      {
        return true;
      }
      for(int i = 0;i < candidate_count;i++)
      {
        if(locked[i][winner]==true)
        {
            return check_cycle(i , loser);
        }
      }
      return false;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for(int i = 0 ;i < candidate_count;i++)
    {
        int false_count = 0;
        for(int j = 0;j < candidate_cout;i++)
        {
            if(locked[j][i]==false)
            {
                false_count++;
                if(false_count == candidate_count)
                {
                    printf("winner = %s\n",candidate[i]);
                }
            }
        }
    }
    return;
}




void record_preferences(int ranks[])
{
    // TODO
    int f = 0;
    int s = 0;
    for(int i = 0;i < candidate_count;i++)
    {
        for(int j = i+1;j < candidate_count;j++)
        {
            f = ranks[i];
            s = ranks[j];
            if( f != s)
            {
               preferences[f][s] ++;
            }
            else
            {
                preferences[s][f] = 0;
            }
        }
    }
    return;
}