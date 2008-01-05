/*#io
docCopyright("Steve Dekorte", 2002)
docLicense("BSD revised")
*/

#ifndef IoSandbox_DEFINED
#define IoSandbox_DEFINED 1

#include "Common.h"
#include "IoObject.h"
#include "UArray.h"
#include "IoNumber.h"
//#include "IoSeq.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ISSANDBOX(self) \
	IoObject_hasCloneFunc_(self, (IoTagCloneFunc *)IoSandbox_rawClone)

typedef IoObject IoSandbox;

IoSandbox *IoSandbox_proto(void *state);
IoSandbox *IoSandbox_rawClone(IoSandbox *self);
IoSandbox *IoSandbox_new(void *state);

void IoSandbox_free(IoSandbox *self);
void IoSandbox_mark(IoSandbox *self);

IoNumber *IoSandbox_messageCount(IoSandbox *self, IoObject *locals, IoMessage *m);
IoObject *IoSandbox_setMessageCount(IoSandbox *self, IoObject *locals, IoMessage *m);
IoNumber *IoSandbox_timeLimit(IoSandbox *self, IoObject *locals, IoMessage *m);
IoObject *IoSandbox_setTimeLimit(IoSandbox *self, IoObject *locals, IoMessage *m);

IoObject *IoSandbox_doSandboxString(IoSandbox *self, IoObject *locals, IoMessage *m);

void IoSandbox_cleanState(IoSandbox *self);
void IoSandbox_addPrintCallback(IoSandbox *self);
void IoSandbox_printCallback(void *voidSelf, const UArray *ba);

#ifdef __cplusplus
}
#endif
#endif
