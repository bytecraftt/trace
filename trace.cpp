#include "Trace.h"

int main(int argc, char **argv)
{
    Trace::SetTraceLevelFlag(Level::DEBUG | Level::INFORMATION);

    {
        Trace tr("Trace1");
    }

    {
        Trace tr(Level::ALL, "Trace2");
    }

    {
        Trace tr(Level::DEBUG, "Trace3");
    }

    {
        Trace tr(Level::ERROR, "Trace4");
    }

    Trace::SetTraceLevelFlag(Level::WARRNING);

    {
        Trace tr(Level::INFORMATION, "Trace5");
    }

    {
        Trace tr(Level::WARRNING, "Trace6");
    }

    return 0;
}