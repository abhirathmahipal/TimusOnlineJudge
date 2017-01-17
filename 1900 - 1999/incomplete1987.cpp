#include <iostream>
using namespace std;

// Note:- This technique helps but still results in Time Limit Exceeded
// Searching from the last segment can save time. If a suitable
// segment is encountered, we can directly skip instead of 
// iterating through everything.

// Since the above mentioned method still exceeded time limit
// have to resort to creating a tree or using a stack

int main()
{
    int seg_count, query_count, seg[100001][3], temp, counter = 0;

    typedef struct tree_node
    {
        int seg_number;
        struct tree_node *lesser_seg;
        struct tree_node *greater_seg;
    } node;
    
    cin >> seg_count;

    for(int i = 1; i <= seg_count; i++)
    {
        cin >> seg[i][0] >> seg[i][1];
        seg[i][2] = i;
    }

    cin >> query_count;

    for(int i = 0; i < query_count; i++)
    {
        cin >> temp;
        
       

        for(int j = seg_count; j > 0; j--)
        {
            if(temp >= seg[j][0] && temp <= seg[j][1])
            {
                counter = j;
                break;
            }

        }



        cout << (counter == 0 ? -1 : counter) << endl; 
        counter = 0;
    }



    return 0;
}
