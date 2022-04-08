template<typename Iterator1, typename Iterator2, typename Pred>
Iterator2 copy_if(Iterator1 current, Iterator2 stop, Iterator2 to, Pred pred)
{
   while (current != stop)
   {
      if (pred(*current))
         *to = *current;
      ++current;
      ++to;
   }
   return to;
}
