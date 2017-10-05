vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
	// sorting algorithm by k
	// then move person by i+1 - k 

	sort(people.begin(), people.end(), sortByK);

	// double loop
	// for ieach index, count the number of elements bigger, 
	// compare count with k,
	// if count is bigger, shift object until count == k
	int count = 0;
	pair<int, int> temp;

	for (int i = 0; i < people.size(); i++) {
		cout << people[i].first << ", " << people[i].second << endl;
	}

	for (int i = 0; i < people.size(); i++) {
		count = 0;
		for (int j = 0; j < i; j++) {
			if (people[j].first >= people[i].first) {
				count++;
			}
		}
		// if count is bigger, put in correct spot
		if (count > people[i].second) {
			temp = people[i];
			people.erase(people.begin() + i); // - 1?
			people.insert(people.begin() + (i - (count - temp.second)), temp);
		}
	}

	return people;
}

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
