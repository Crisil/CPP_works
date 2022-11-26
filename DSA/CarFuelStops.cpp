// A program to detrmine minimum number of stop required to
// a cover a distance of d given there are N number of 
// refill points at distance s1, s2 ... sn. Assume with
// one full tank can cover m distance and starts initiall
// with full tank

#include <iostream>
#include <vector>
using namespace::std;

template<typename T>
void display(vector<T>vec) {
	for (auto v : vec)
		cout << v << ", ";
	cout << endl;
}

// Calculate minimum number of refils required
// return number of minimum stops
//  -1 : not possible to reach destination
//  act_stop_points : Actually stopped distance points
int MinRefillPoints(int distance2cover, int limit, vector<int> avl_refill_points, vector<int>& act_stop_points) {
	int n_min_stops = 0;							// minimum number of stops
	int n_val_stops;								  // total number of refill points
	int distance_covered = 0;					// total distance covered
	int nxt_possible2cover = limit;		// distance possible to cover after refill
	int loc = 0;
	cout << "MinRefillPoints ... " << endl;

	// Append starting distance and destination distance to the refill points
  avl_refill_points.emplace(avl_refill_points.begin(), 0);
	avl_refill_points.push_back(distance2cover);
	n_val_stops = avl_refill_points.size();

	// Destination reached? exit!
	while (distance_covered < distance2cover) {
		for (loc = 0; loc != avl_refill_points.size(); ++loc) {
			auto nxt_loc = loc + 1;
      // Stop at points if distance to be covered till is less than refill limit and next point is not reachable
			if (avl_refill_points[loc] <= nxt_possible2cover && avl_refill_points[nxt_loc] > nxt_possible2cover) {
				// Covered this much distance and there is stop for refill
				distance_covered = avl_refill_points[loc];
				n_min_stops++;
				act_stop_points.push_back(avl_refill_points[loc]);
				// Remove all previous points from refill locations
				avl_refill_points.erase(avl_refill_points.begin(), avl_refill_points.begin()+loc);
				// Calc next possible distance which can be travelled
				nxt_possible2cover = distance_covered + limit;
				// Can we reach next possible stop, else distance can't be reached!!
				if (nxt_possible2cover < avl_refill_points[1])
					return -1;
				break;
			}
		}
		// Next location is the destination :)
		if (nxt_possible2cover >= distance2cover)
			break;
	}
	return n_min_stops;
}

int main(){
	int num_stops;
	int distance2cover;
	int distance_per_refill;
	int tmp;
	vector<int> avl_refill_points;
	vector<int> act_stop_points;		// points at which refill happened
	int min_num_refills;

	cout << "Enter distance to cover : ";
	cin >> distance2cover;
	cout << "Distance per refill : ";
	cin >> distance_per_refill;
	cout << "Number of refill points : ";
  cin >> num_stops;
	cout << "Refill locations distance from start : ";
	for (int i = 0; i != num_stops; ++i) {
		cin >> tmp;
		avl_refill_points.push_back(tmp);
	}

	min_num_refills = MinRefillPoints(distance2cover, distance_per_refill, avl_refill_points, act_stop_points);
	cout << "Minimum Refill Points : " << min_num_refills << endl;
	cout << "Stops @ ";
	display(act_stop_points);

	return 0;
}
