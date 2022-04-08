template<typename Iterator, typename T>
bool binary_search2(Iterator start, Iterator stop, const T& value)
{
   if (start == stop)
      return false;
   int low = 0;
   int high = (stop - start); // number of elements 
   while (low < high) {
      int mid = (low + high) / 2;
      if (start[mid] == value)
	 return true;
      else if (start[mid] < value)
	 low = mid+1;
      else
	 high = mid;
   }
   return false;
}

template<typename Iterator, typename T>
Iterator lower_bound2(Iterator start, Iterator stop, const T& value)
{
   int low = 0;
   int high = (stop - start); // number of elements 
   while (low < high) {
      int mid = (low + high) / 2;
      if (start[mid] < value)
	 low = mid+1;
      else
	 high = mid;
   }
   return start+low;
}

template<typename Iterator, typename T>
Iterator upper_bound2(Iterator start, Iterator stop, const T& value)
{
   int low = 0;
   int high = (stop - start); // number of elements 
   while (low < high) {
      int mid = (low + high) / 2;
      if (start[mid] <= value)
	 low = mid+1;
      else
	 high = mid;
   }
   return start+low;
}
