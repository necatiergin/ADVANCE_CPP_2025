#include <utility>

template <typename InIter, typename OutIter>
OutIter Copy(InIter beg, InIter end, OutIter destbeg)
{
	while (beg != end) {
		*destbeg++ = *beg++;
	}

	return destbeg;
}

template <typename InIter, typename OutIter>
OutIter Move(InIter beg, InIter end, OutIter destbeg)
{
	while (beg != end) {
		*destbeg++ = std::move(*beg++);
	}

	return destbeg;
}
