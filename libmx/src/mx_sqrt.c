int mx_sqrt(int x) {
	int result = 0;
    
	for (int i = 1; x > 0; i += 2) {
		x -= i;
		result++;
	}
    return (x == 0) ? result : 0;
}
