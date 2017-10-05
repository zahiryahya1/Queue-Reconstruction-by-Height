vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
	
	// sort the vector by k values
	sort(people.begin(), people.end(), sortByK);

	// for ieach index, count the number of elements bigger
	// compare count with k
	// if count is bigger place the object in the correct index
	
	int count = 0;
	pair<int, int> temp;
	
	
	for (int i = 0; i < people.size(); i++) {
		count = 0;
		
		// count the number of people taller then current person
		for (int j = 0; j < i; j++) {
			if (people[j].first >= people[i].first) {
				count++;
			}
		}
		
		// if count is bigger, put in correct index by removing the old value
		// and interting the new value
		if (count > people[i].second) {
			temp = people[i];
			people.erase(people.begin() + i);
			people.insert(people.begin() + (i - (count - temp.second)), temp);
		}
	}

	return people;
}

// sorting algorithm by k, if k's are equal then sort by h 
static bool sortByK(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.second < b.second)
		return true;
	if (a.second == b.second) {
		if (a.first < b.first)
			return true;
		else
			return false;
	}
	return false;
}
