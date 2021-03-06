#pragma once
#include "Button.h"
#include "Element.h"
#include "Menu.h"
#include "Types.h"

class UIItem : public Element
{
public:
    UIItem();
    ~UIItem();

    //这里注意，用来显示物品图片的按钮的纹理编号实际就是物品编号
    std::vector<Button*> item_buttons_;
    TextBox* cursor_ = nullptr;

    int leftup_index_ = 0; //左上角第一个物品在当前种类列表中的索引

    const int item_each_line_ = 7;
    const int line_count_ = 3;

    MenuText* title_ = nullptr;

    int force_item_type_ = -1;

    bool select_user_ = true;

    MenuText* getTitle() { return title_; }

    void setForceItemType(int f);

    void setSelectUser(bool s) { select_user_ = s; }

    int getItemDetailType(Item* item);
    Item* getAvailableItem(int i);

    void geItemsByType(int item_type);

    void checkCurrentItem();
    virtual void draw() override { showItemProperty(current_item_); }
    virtual void dealEvent(BP_Event& e) override;

    void showItemProperty(Item* item);
    void showOneProperty(int v, std::string format_str, int size, BP_Color c, int& x, int& y);

    Item* current_item_ = nullptr;
    std::vector<Item*> available_items_;
    Button* current_button_ = nullptr;

    Item* getCurrentItem() { return current_item_; }

    virtual void onPressedOK() override;
    virtual void onPressedCancel() override;
};
