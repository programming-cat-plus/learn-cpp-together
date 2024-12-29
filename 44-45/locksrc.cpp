
template <typename L1, typename L2, typename... L3>
void lock(L1 &l1, L2 &l2, L3 &...l3)
{
    if constexpr (is_same_v<L1, L2> && (is_same_v<L1, L3> && ...))
    {
        constexpr int N = 2 + sizeof...(L3);
        unique_lock<L1> locks[] = {
            {l1, defer_lock}, {l2, defer_lock}, {l3, defer_lock}...};
        int first = 0;
        do
        {
            locks[first].lock();
            for (int j = 1; j < N; ++j)
            {
                const int idx = (first + j) % N;
                if (!locks[idx].try_lock())
                {
                    for (int k = j; k != 0; --k)
                        locks[(first + k - 1) % N].unlock();
                    first = idx;
                    break;
                }
            }
        } while (!locks[first].owns_lock());

        for (auto &l : locks)
            l.release();
    }
    else
    {
        int i = 0;
        __detail::lock_impl(i, 0, l1, l2, l3...);
    }
}