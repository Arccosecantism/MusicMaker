//
//template <class C> Distribution<C>::Distribution()
//
//
//
//template <class C> void Distribution<C>::addRelativeChance(const unsigned int& chance, const C& obj)
//{
//	probabilities.push_back(chance);
//	objVec.push_back(obj);
//	intervals.clear();
//
//	unsigned int totLcm = 1;
//	for (unsigned int i = 0; i < probabilities.size(); i++)
//	{
//		totLcm = lcm(totLcm, probabilities[i]);
//	}
//
//	unsigned int sum = 0;
//	unsigned int oldSum = 0;
//	for (unsigned int i = 0; i < probabilities.size(); i++)
//	{
//		sum += totLcm / probabilities[i];
//		intervals.push_back(std::make_pair(oldSum, sum));
//		oldSum = sum;
//	}
//	distMax = sum;
//
//}
//
//template <class C> C Distribution<C>::generateObj()
//{
//
//}
//
//
//template <class C> unsigned int Distribution<C>::gcf(unsigned int a, unsigned int b)
//{
//
//
//}
//
//
//template <class C> unsigned int Distribution<C>::lcm(const unsigned int& a, const unsigned int& b)
//{
//	return a * b / gcf(a, b);
//}
//
//
//template <class C> bool Distribution<C>::isInInterval(const unsigned int& val, const unsigned int& beg, const unsigned int& endd)
//{
//	return ((val >= beg) && (val < endd));
//}
//
//
//template <class C> unsigned int Distribution<C>::randVal()
//{
//	srand(time(NULL));
//	return rand() % distMax;
//
//}
