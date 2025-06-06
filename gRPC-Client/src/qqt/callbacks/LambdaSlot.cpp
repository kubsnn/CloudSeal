#include "LambdaSlot.hpp"

namespace cloudseal::qqt::callbacks
{
	void LambdaSlot0::call()
	{
		Base::call();
	}

	void LambdaSlot1::call(QVariant arg0)
	{
		Base::call(std::move(arg0));
	}

	void LambdaSlot2::call(QVariant arg0, QVariant arg1)
	{
		Base::call(std::move(arg0), std::move(arg1));
	}

	void LambdaSlot3::call(QVariant arg0, QVariant arg1, QVariant arg2)
	{
		Base::call(std::move(arg0), std::move(arg1), std::move(arg2));
	}

	void LambdaSlot4::call(QVariant arg0, QVariant arg1, QVariant arg2, QVariant arg3)
	{
		Base::call(std::move(arg0), std::move(arg1), std::move(arg2), std::move(arg3));
	}
}