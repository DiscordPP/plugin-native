//
// Created by Aidan on 11/9/2021.
//

#ifndef DEFINE_OBJECT_OPEN
#error There is no open Object definition
#endif
};

#undef Name

#ifdef Parent
#undef Parent
#endif

#undef Fields

#ifdef ToJsonExtra
#undef ToJsonExtra
#endif

#ifdef FromJsonExtra
#undef FromJsonExtra
#endif

#undef DEFINE_OBJECT_OPEN
