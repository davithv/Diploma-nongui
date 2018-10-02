#pragma once/*
#include "Row.h"

template<class In>
void insertion_sort(In b, In e) { // pretty standard insertion sort for smaller pieces
	for (auto i = b; i != e; ++i) {
		auto key = *i;
		auto j = i - 1;

		for (; j != b - 1 && *j > key; --j)
			*(j + 1) = *j;

		*(j + 1) = key;
	}
}

template <class In>
void merge(In b, In m, In e) { // this is the merger, doing the important job
	std::vector<typename In::value_type> left(b, m);
	std::vector<typename In::value_type> right(m, e);

	// guards for the two ranges
	left.push_back(std::numeric_limits<typename In::value_type>::max());
	right.push_back(std::numeric_limits<typename In::value_type>::max());

	auto itl = std::begin(left);
	auto itr = std::begin(right);

	while (b != e) {
		if (*itl <= *itr)
			*b++ = *itl++;
		else
			*b++ = *itr++;
	}
}

template <class In>
void merge_sort(In b, In e) { // serial merge_sort, used for pieces smaller < 500
	if (b < e - 1) {
		auto dis = std::distance(b, e) / 2;
		In m = b + dis;

		if (dis > 10) {
			merge_sort(b, m);
			merge_sort(m, e);
			merge(b, m, e);
		}
		//switch to insertion sort for pieces < 10
		else
			insertion_sort(b, e);
	}
}

template <class In>
void merge_sort_parallel(In b, In e) { // merge_sort parallel 
	if (b != e - 1) {
		auto dis = std::distance(b, e);
		In m = b + dis / 2;
		if (dis > 500) {
			tbb::parallel_invoke([&]() { merge_sort_parallel(b, m); },
				[&]() { merge_sort_parallel(m, e); });
		}
		else {
			merge_sort(b, m);
			merge_sort(m, e);
		}
		merge(b, m, e);
	}
}

*/