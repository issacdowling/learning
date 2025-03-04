void swap_strings(char **a, char **b) {
	char* old_a = *a;
	*b = *a;
	*a = old_a;
}
