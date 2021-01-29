#include <assert.h>
#include "slist.h"
#include <stdio.h>

int main()
{
	Slist s = slist_new();
	Slist *list = &s;


	list = slist_add_head(list, 10);
	list = slist_add_head(list, 20);
	list = slist_add_head(list, 30);
	list = slist_add_head(list, 40);


	assert (slist_length(list) == 4);
	list = slist_delete_head(list);
	assert (slist_length(list) == 3);

	list = slist_add_tail(list, 50);
	assert (slist_length(list) == 4);

	list = slist_delete_head(list);
	assert (slist_length(list) == 3);

	list = slist_delete_tail(list);
	assert (slist_length(list) == 2);

	assert (slist_lookup(list, 100)== 0);


	int32_t min,max;
	assert(slist_min(list)==10);
	assert(slist_max(list)==20);


	list = slist_spec_ele(list,100,20);
	assert (slist_length(list) == 3);


	list = slist_spec_ele_delete(list,20);
	assert (slist_length(list) == 2);


	list = reverse_list(list);


	Slist s1 = slist_new();
	Slist *list1 = &s1;

	list1 = slist_add_head(list1, 100);
	list1 = slist_add_head(list1, 10);

	int32_t c= list_compare(list,list1);
	assert(list_compare(list,list1)==0);

	list1 = slist_add_tail(list1,40);

	Slist u = slist_new();
	Slist *union_list = &u;

	list1 = slist_add_head(list1, 30);


	union_list = union_twolist(union_list,list,list1);
	assert (slist_length(union_list) == 4);



	Slist i = slist_new();
	Slist *intersection_list = &i;

	intersection_list= intersection_twolist(intersection_list,list,list1);
	assert (slist_length(intersection_list) == 1);


	list1 = unique_slist(list1,40);
	assert(slist_length(list1)==4);

	list1 = unique_slist(list1,50);
	assert(slist_length(list1)==5);

	return 0;
}
