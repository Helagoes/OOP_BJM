#include "participant.h"
#include "ntime.h"

participant::participant(const participant &ref)
	{
		count++;
		this->name = ref.name;
		this->runtime = ref.runtime;
	}
