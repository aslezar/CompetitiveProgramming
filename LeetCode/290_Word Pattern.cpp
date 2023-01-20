bool wordPattern(string pattern, string s) {
	map<string,char> m;
	map<char,string> mp;
	int word=0;
	string t;
	stringstream str(s);
	while(str>>t)
	{
	    auto it=m.find(t);
	    if (it != m.end()) {
		if(it->second!=pattern[word])
		    return false;
	    }

	    auto it2=mp.find(pattern[word]);
	    if (it2 != mp.end()) {
		if(it2->second!=t)
		    return false;
	    }
	    
	    m[t]=pattern[word];
	    mp[pattern[word]]=t;
	    word++;
	}

	if(word!=pattern.length())
	    return false;

	// auto it3=m.begin();
	// while (it3 != m.end())
	// {
	//     std::cout << "Key: " << it3->first << ", Value: " << it3->second << std::endl;
	//     ++it3;
	// }

	// cout<<'\n';

	// auto it4=mp.begin();
	// while (it4 != mp.end())
	// {
	//     std::cout << "Key: " << it4->first << ", Value: " << it4->second << std::endl;
	//     ++it4;
	// }

	return true;
}
