#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;

#include <boost/lambda/lambda.hpp>
#include <iterator>
#include <algorithm>


void EigneTest();

int main()
{
    EigneTest();
    return 0;
}

void EigneTest()
{
  MatrixXd m(2,2);
  m(0,0) = 3;
  m(1,0) = 2.5;
  m(0,1) = -1;
  m(1,1) = m(1,0) + m(0,1);
  std::cout << m << std::endl;
}
// Header only
void BoostSimpleTest(){
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::for_each(
        in(std::cin), in(), std::cout << (_1 * 3) << " " );
}
