#include <rpc.h>

int uuid(UUID *uuid){
	int ret = UuidCreateSequential(uuid);
	if (ret == RPC_S_OK){
		return TRUE;
	}
}