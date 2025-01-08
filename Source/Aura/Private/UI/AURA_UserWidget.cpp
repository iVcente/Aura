// Copyright Dancing Man Games. All Rights Reserved.


#include "UI/AURA_UserWidget.h"

void UAURA_UserWidget::SetWidgetController(UObject* NewWidgetController)
{
	WidgetController = NewWidgetController;
	OnWidgetControllerSet();
}
