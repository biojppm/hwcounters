// https://docs.microsoft.com/en-us/windows/desktop/perfctrs/enumerating-process-objects

// This program needs only the essential Windows header files.
#define WIN32_LEAN_AND_MEAN 1

#include <windows.h>
#include <malloc.h>
#include <stdio.h>
#include <pdh.h>
#include <pdhmsg.h>

#pragma comment(lib, "pdh.lib")

CONST PSTR COUNTER_OBJECT = "Process";

void main(void)
{
    PDH_STATUS status = ERROR_SUCCESS;
    LPSTR psCounterListBuffer = nullptr;
    DWORD dCounterListSize = 0;
    LPSTR psInstanceListBuffer = nullptr;
    DWORD dInstanceListSize = 0;
    LPSTR pTemp = nullptr;
    
    // Determine the required buffer size for the data.
    status = PdhEnumObjectItemsA(
        nullptr,               // real-time source
        nullptr,               // local machine
        COUNTER_OBJECT,        // object to enumerate
        psCounterListBuffer,   // pass nullptr and 0
        &dCounterListSize,     // to get required buffer size
        psInstanceListBuffer,
        &dInstanceListSize,
        PERF_DETAIL_WIZARD,     // counter detail level
        0);
    
    if (status == PDH_MORE_DATA)
    {
        // Allocate the buffers and try the call again.
        psCounterListBuffer = (LPSTR)malloc(dCounterListSize * sizeof(CHAR));
        psInstanceListBuffer = (LPSTR)malloc(dInstanceListSize * sizeof(CHAR));

        if (nullptr != psCounterListBuffer)
        {
            status = PdhEnumObjectItemsA(
                nullptr,                   // real-time source
                nullptr,                   // local machine
                COUNTER_OBJECT,         // object to enumerate
                psCounterListBuffer,
                &dCounterListSize,
                psInstanceListBuffer,
                &dInstanceListSize,
                PERF_DETAIL_WIZARD,     // counter detail level
                0);

            if (status == ERROR_SUCCESS)
            {
                printf("Counters that the Process objects defines:\n\n");

                // Walk the counters list. The list can contain one
                // or more nullptr-terminated strings. The list is terminated
                // using two nullptr-terminator characters.
                for (pTemp = psCounterListBuffer; *pTemp != 0; pTemp += strlen(pTemp) + 1)
                {
                     printf("%s\n", pTemp);
                }

                //printf("\nInstances of the Process object:\n\n");
                //
                //// Walk the instance list. The list can contain one
                //// or more nullptr-terminated strings. The list is terminated
                //// using two nullptr-terminator characters.
                //for (pTemp = psInstanceListBuffer; *pTemp != 0; pTemp += strlen(pTemp) + 1)
                //{
                //     printf("%s\n", pTemp);
                //}
            }
            else
            {
                printf("Second PdhEnumObjectItems failed with 0x%x.\n", status);
            }
        }
        else
        {
            printf("Unable to allocate buffers.\n");
            status = ERROR_OUTOFMEMORY;
        }
    }
    else
    {
        printf("\nPdhEnumObjectItems failed with 0x%x.\n", status);
    }

    if (psCounterListBuffer != nullptr)
        free (psCounterListBuffer);

    if (psInstanceListBuffer != nullptr)
        free (psInstanceListBuffer);



    //PZZSTR mszObjectList = nullptr;
    //DWORD dObjectListSize = 0;
    //
    //status = PdhEnumObjectsA(
    //    nullptr,                   // real-time source
    //    nullptr,                   // local machine
    //    mszObjectList,             // Caller-allocated buffer that receives the list of object names
    //    &dObjectListSize,          // Size of the mszObjectList buffer, in TCHARs
    //    PERF_DETAIL_WIZARD,        // Detail level of the performance items to return
    //    TRUE                       // whether cached object list should be automatically refreshed
    //);
    //
    //if(status == PDH_MORE_DATA)
    //{
    //    mszObjectList = (PZZSTR)malloc(dObjectListSize * sizeof(TCHAR));
    //
    //    status = PdhEnumObjectsA(
    //        nullptr,                   // real-time source
    //        nullptr,                   // local machine
    //        mszObjectList,             // Caller-allocated buffer that receives the list of object names
    //        &dObjectListSize,          // Size of the mszObjectList buffer, in TCHARs
    //        PERF_DETAIL_WIZARD,        // Detail level of the performance items to return
    //        FALSE                      // whether cached object list should be automatically refreshed
    //    );
    //    if (nullptr != mszObjectList)
    //    {
    //
    //        if (status == ERROR_SUCCESS)
    //        {
    //            printf("\n\n-----------------------------------------\n");
    //            printf("Counters that the Process objects defines:\n\n");
    //            // Walk the counters list. The list can contain one
    //            // or more nullptr-terminated strings. The list is terminated
    //            // using two nullptr-terminator characters.
    //            for (pTemp = mszObjectList; *pTemp != 0; pTemp += strlen(pTemp) + 1)
    //            {
    //                 printf("%s\n", pTemp);
    //            }
    //        }
    //        else
    //        {
    //            printf("Second PdhEnumObjectsA failed with 0x%x.\n", status);
    //        }
    //    }
    //}
}
