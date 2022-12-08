int mx_strncmp(const char *s1, const char *s2, int n) {
    if (!s1 || !s2) {
        return 0;
	}

	for (int i = 0; i < n && s1[i] != '\0'; i++) {
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
	}
	return *s1 - *s2;
}
