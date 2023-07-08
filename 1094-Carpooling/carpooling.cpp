/*
1094. Car Pooling
Medium
3.9K
80
Companies

There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

 

Example 1:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false

Example 2:

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true

 

Constraints:

    1 <= trips.length <= 1000
    trips[i].length == 3
    1 <= numPassengersi <= 100
    0 <= fromi < toi <= 1000
    1 <= capacity <= 105
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool pairCompare (pair<int,int> a, pair<int,int> b){
	return a.first < b.first;
}

bool carPooling(vector<vector<int>>& trips, int capacity) {

	vector<pair<int,int>> pickups, dropoffs;

	for(auto trip : trips){
		int numPassengers = trip[0], pickupDist = trip[1], dropoffDist = trip[2];
		pickups.push_back(make_pair(pickupDist, numPassengers));
		dropoffs.push_back(make_pair(dropoffDist, numPassengers));
	}
	
	//Sort pickup and dropoff times
	sort(pickups.begin(), pickups.end(), pairCompare);
	sort(dropoffs.begin(), dropoffs.end(), pairCompare);
	
	/*
	cout<<"Pickups"<<endl;
	for(int i = 0; i < trips.size(); i++){
		cout<<pickups[i].first<<" "<<pickups[i].second<<endl;
	}

	cout<<"Dropoffs"<<endl;
	for(int i = 0; i < trips.size(); i++){
		cout<<dropoffs[i].first<<" "<<dropoffs[i].second<<endl;
	}
	*/

	//Start at the beginning of each array
	//Drop off as many people as possible until we have to pickup more people
	//Update capacity, if capacity < 0 return -1
	//If we get through both arrays, return true as the capacity was never exceeded during the trips
	unsigned int pIdx = 0, dIdx = 0;
	int currCapacity = capacity;

	while(pIdx < trips.size()){
		while(dIdx < trips.size() && dropoffs[dIdx].first <= pickups[pIdx].first){
			currCapacity += dropoffs[dIdx].second;
			dIdx++;
		}
		
		currCapacity -= pickups[pIdx].second;
		pIdx++;

		if(currCapacity < 0)
			return false;
	}

	return true;
}

int main(){

	vector<vector<int>> inputTrip;
	int inputCapacity;

	inputTrip = {{2,4,5}, {3,3,7}};
	inputCapacity = 5;

	cout<<carPooling(inputTrip, inputCapacity)<<endl;

	inputTrip = {{2,1,5}, {3,5,7}};
	inputCapacity = 3;
	cout<<carPooling(inputTrip, inputCapacity)<<endl;
}

