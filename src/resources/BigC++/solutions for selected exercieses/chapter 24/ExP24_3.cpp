template<typename Iterator, typename Pred>
Iterator find_if(Iterator current, Iterator stop, Pred pre)
{
   while (current != stop)
   {
      if (pred(*current))
	 return current;
      ++current;
   }
   return stop;
}

template<typename Iterator, typename Pred>
void count_if(Iterator current, Iterator stop, Pred pred)
{
   int count = 0;
   while (current != stop)
   {
      if (pred(*current))
	 ++count;
      ++current;
   }
   return count;
}

template<typename Iterator, typename Pred, typename Value>
void replace_if(Iterator current, Iterator stop, Pred pred, Value a)
{
   while (current != stop)
   {
      if (pred(*current))
	 *current = a;
      ++current;
   }
}

template<typename Iterator1, typename Iterator2, typename Pred> 
Iterator2 remove_copy_if(Iterator1 current, Iterator1 stop, Iterator2 to, Pred pred)
{
   while (current != stop)
   {
      if (pred(*current))
      {
	 *to = *current;
	 ++to;
      }
      ++current;
   }
}
