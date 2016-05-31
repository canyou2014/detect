#ifndef DETECT1_H
#define DETECT1_H
#include <boost/array.hpp>
#include <vector>
typedef std::vector< boost::array<double, 3> > vec;
class detect1
{
    public:
        detect1();

        virtual ~detect1();
        void state(double acc[], double T, bool& current_state);
        void avg(vec v, int begin, int end, double* avgd);
    protected:
    private:
        vec v;
        double sd[3][5];
        boost::array<double ,3> ac;
        double avgd[3];
        double delta[3];
};

#endif // DETECT1_H
