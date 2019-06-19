int hash_func(const int& val, const int&mod = 0)
{
	if(mod > 0)
		return val % mod;
	else if (mod == 0)
		return val;
	else
		return 0;
}
