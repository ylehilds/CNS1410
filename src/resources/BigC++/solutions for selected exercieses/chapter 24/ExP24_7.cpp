// you may have to tell the students about iter_swap.

template<typename Iterator>
void reverse2(Iterator p, Iterator q)
{
   while (p != q)
   {
      --q;
      if (p == q) return;
      // swap the two values
      iter_swap(p, q);
      ++p;
   }
}
