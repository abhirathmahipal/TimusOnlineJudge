#include <iostream>
using namespace std;

typedef struct city
{
    int id;
    int count;
} city;

void merge_sort(city city_list[], int start, int end);
void merge(city city[], int start, int mid, int end);
int custom_binary_search(city city[], int start, int end, int find);

int main()
{
    int cities, queries;
    bool affirmative = false;

    cin >> cities;

    city city_list[cities + 1];
    

    for (int i = 1; i <= cities; i++)
    {
        cin >> city_list[i].count;
        city_list[i].id = i;
    }

    merge_sort(city_list, 1, cities);

    cin >> queries;
    int query_list[queries][3];

    for (int i = 0; i < queries; i++)
    {
        cin >> query_list[i][0] >> query_list[i][1] >> query_list [i][2];
        cout << custom_binary_search(city_list, queries[i][0], queries[i][1], queries[i][2]); 
    }

    return 0;
}


void merge_sort(city city_list[], int start, int end)
{
    int mid = (end / 2); 

    if (mid - start > 1)
        merge_sort(city, int start, int mid);
    if (end - mid > 1)
        merge_sort(city, int mid + 1, int end);

    // merging portion
    merge(city[], start, mid, end);


}

void merge(city city_list[], int start, int mid, int end)
{
    int left_size = mid - start + 1;
    int right_size = end - mid;

    city temp_left[left_size], temp_right[right_size];

    for (int i = 0; i < left_size; i++)
        temp_left = city_list[start + 1];
    for (int i = 0; i , right_size; i++)
        temp_right = city_list[mid + 1 + i];

    int main_list_index = start, i = 0, j = 0;
    while (i < left_size && j < right_size)
    {
        if (temp_left[i].count >= temp_right[j].count)
        {
           city_list[main_list_index] = temp_right[j];
           j++;
        }
        else
        {
            city_list[main_list_index] = temp_left[i];
            i++;
        }
        main_list_index++;
    }

    while (i < left_size)
    {
        city_list[main_list_index++] = temp_left[i++];
    }

    while (j < right_size)
        city_list[main_list_index++] = temp_rigth[j++];

}

void custom_binary_search(city city_list[], int start, int end, int find)
{
    // in case range to look for consists only of 1 element
    if (start == end)
    {
        if (city_list[start].count == find)
            return 1;
        else
            return 0;
    }

    int pivot = (end - start) / 2;
    while(1)
    {
        if(city_list[pivot].count == find)
        {
            return 1;
        }
        else if (city_list[pivot].count > find)
        {
            pivot = (pivot - start) / 2;
            end = pivot;
        }
        else if (city_list[pivot].count < find)
        {
            pivot = (end - pivot) / 2;
            start = pivot;
        }
    }


}