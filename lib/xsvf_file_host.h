#ifndef CODIBLE_XSVF_FILE_HOST_H_
#define CODIBLE_XSVF_FILE_HOST_H_

#include "xsvf_host.h"
#include <istream>

namespace codible
{
class XSVF_File_Host : public XSVF_Host
{
public:
    XSVF_File_Host(std::istream && stream);
    XSVF_File_Host(std::istream & stream);

    virtual int setup() override;
    virtual int shutdown() override;
    virtual int sync() override;
    virtual int getbyte() override;
    virtual void * realloc(void * ptr, int size, enum libxsvf_mem which) override;
    virtual void report_tapstate() override;
    virtual void report_status(const char * message) override;

private:
    std::istream & stream_;
};
} // namespace codible

#endif // CODIBLE_XSVF_FILE_HOST_H_
