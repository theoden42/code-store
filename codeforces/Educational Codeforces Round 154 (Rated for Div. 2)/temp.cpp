string s;
cin >> s;

int count1 = 0;
for(int i = 0; i < s.size(); i++){
	if(i % 2 == 0){
		if(s[i] != '0')
			count1 += 1;
	} else {
		if(s[i] != '1')
			count1 += 1;
	}
}

int count2 = 0;
for(int i = 0; i < s.size(); i++){
	if(i % 2 == 0){
		if(s[i] != '1')
			count2 += 1;
	} else {
		if(s[i] != '2')
			count2 += 1;
	}
}

return min(count1, count2);