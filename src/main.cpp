#include <iostream>
#include <CoreServices/CoreServices.h>

using std::cout;
using std::endl;

int main()
{
  /* Define variables and create a CFArray object containing
     CFString objects containing paths to watch.
   */
  CFStringRef mypath = CFSTR("/tmp/test");
  CFArrayRef pathsToWatch = CFArrayCreate(NULL, (const void **)&mypath, 1, NULL);
  void *callbackInfo = NULL; // could put stream-specific data here.
  FSEventStreamRef stream;
  CFAbsoluteTime latency = 3.0; /* Latency in seconds */

  /* Create the stream, passing in a callback */
  stream = FSEventStreamCreate(NULL,
      &myCallbackFunction,
      callbackInfo,
      pathsToWatch,
      kFSEventStreamEventIdSinceNow, /* Or a previous event ID */
      latency,
      kFSEventStreamCreateFlagNone /* Flags explained in reference */
  );
}
