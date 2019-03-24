void tausche(int*& ptr_a, int*& ptr_b)
{
	int* temp = ptr_a;
	ptr_a = ptr_b;
	ptr_b = temp;
}
