 // ============================================================================
// File: PrecondViolatedExcept.h
// ============================================================================
// Header file for the class PrecondViolatedExcept
// ============================================================================

#ifndef PRECONDVIOLATEDEXCEPT_HEADER
#define PRECONDVIOLATEDEXCEPT_HEADER

#include <string>
using namespace std;

class PrecondViolatedExcept
{
    public:
        // =====================================================================
        //      Constructors and Destructor
        // =====================================================================

        /** Initializes m_errorMsg to errorMsg. */
        PrecondViolatedExcept(const string errorMsg);

        /** Compiler provided copy constructor and destructor will suffice.  */

        // =====================================================================
        //      Member Functions
        // =====================================================================

        /** Returns the message  of the class private data member
         @param Nothing.
         @return  A string. */
        std::string     GetMsg() const;

        /** Sets the error message of the class private data member
         @param errorMsg:  A string (passed by value) to update m_errorMsg.
         @return  Nothing. */
        void                    SetMsg(const string errorMsg);

    private:
        // =====================================================================
        //      Data Members
        // =====================================================================
        string             m_errorMsg;

};

#endif
