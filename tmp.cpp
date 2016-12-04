int solution(vector<int> &A) {

unsigned int N = A.size ();
if (N <= 3)
return 0;
auto it = A.begin(); // iterator
auto rit = A.rbegin(); // reverse iterator
std::vector<int> max_left_slice(N,0);
std::vector<int> max_right_slice(N,0);
auto it_mls = max_left_slice.begin();
auto rit_mrs = max_right_slice.rbegin();
int left_partial_sum(*it);
int right_partial_sum(*rit);
int min_left_partial_sum(left_partial_sum);
int min_right_partial_sum(right_partial_sum);

unsigned int y = 1;
while ( y < N - 1)
{
*(it_mls + y) = left_partial_sum - min_left_partial_sum;
left_partial_sum += *(it + y);
if (left_partial_sum < min_left_partial_sum)
min_left_partial_sum = left_partial_sum;

*(rit_mrs + y) = right_partial_sum - min_right_partial_sum;
right_partial_sum += *(rit + y);
if (right_partial_sum < min_right_partial_sum)
min_right_partial_sum = right_partial_sum;

++y;
}

int max_double_sum(0);
auto it_mrs = max_right_slice.begin();
for ( y = 1; y < N - 1; ++y)
if (*(it_mls + y) + *(it_mrs + y) > max_double_sum)
max_double_sum = *(it_mls + y) + *(it_mrs + y) ;

return max_double_sum;
}
