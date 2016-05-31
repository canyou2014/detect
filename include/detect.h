#ifndef DETECT_H
#define DETECT_H

class detect
{
    public:
        detect();

        virtual ~detect();
        void state(double* acc, double T, bool& current_state);
        double avg(double* x, int len);
    protected:
    private:
        double sd[3][5];
        int count;
        double delta[3];

};

#endif // DETECT_H
