#include "ex15_03_Quote.h"
#include "ex15_05_Bulk_quote.h"
#include "ex15_07_Limit_quote.h"
#include "ex15_11_Quote.h"
#include "ex15_11_Bulk_quote.h"
#include "ex15_11_Limit_quote.h"
#include "ex15_15_Disc_quote.h"
#include "ex15_15_Bulk_quote.h"
#include "ex15_16_Limit_quote.h"
#include "ex15_20_Base.h"
#include "ex15_21_GeomtricPrimitives.h"
#include "ex15_26_Quote.h"
#include "ex15_26_Bulk_quote.h"
#include "ex15_27_Bulk_quote.h"
#include "ex15_30_Basket.h"

int main()
{
    cout << "\n===== ex03 =====" << endl;

    EX03::Quote quote_03("0-201-78345-X", 23.8);
    EX03::print_total(cout, quote_03, 3);

    cout << "\n===== ex05 =====" << endl;

    EX05::Bulk_quote bulk_quote("0-201-78345-X", 23.8, 3, 0.5);
    EX03::print_total(cout, bulk_quote, 4);

    cout << "\n===== ex07 =====" << endl;

    EX07::Limit_quote limit_quote("0-201-78345-X", 23.8, 3, 5, 0.5);
    EX03::print_total(cout, limit_quote, 6);

    cout << "\n===== ex11 =====" << endl;

    EX11::Quote quote_11("0-201-82470-1", 50);
    EX11::Bulk_quote bulk_quote_11("0-201-82470-1", 50, 5, .19);
    EX11::Limit_quote limit_quote_11("0-201-82470-1", 50, 5, 10, .19);

    quote_11.debug();
    bulk_quote_11.debug();
    limit_quote_11.debug();

    cout << "\n===== ex15 =====" << endl;

    EX15::Bulk_quote bulk_quote_15("0-201-82470-1", 50, 5, .19);
    EX03::print_total(cout, bulk_quote_15, 6);

    cout << "\n===== ex16 =====" << endl;

    EX16::Limit_quote limit_quote_16("0-201-82470-1", 50, 5, 10, .19);
    EX03::print_total(cout, limit_quote_16, 14);

    cout << "\n===== ex20 =====" << endl;

    //EX20::Pub_Derv d1;
    //EX20::Priv_Derv d2;
    //EX20::Prot_Derv d3;

    //EX20::Derived_from_Public dd1;
    //EX20::Derived_from_Private dd2;
    //EX20::Derived_from_Protected dd3;

    //EX20::Base *p = &d1;
    // p = &d2; // error: inaccessible
    // p = &d3; // error: inaccessible
    //p = &dd1;
    // p = &dd2; // error: inaccessible
    // p = &dd3; // error: inaccessible

    cout << "\n===== ex21 =====" << endl;

    EX21::Box box;
    cout << box.shape_name();
    box.resize_by_percentage(4.f);
    cout << "'s volume = " << box.volume() << endl;

    EX21::Circle circle;
    cout << circle.shape_name();
    circle.resize_by_percentage(2.f);
    cout << "'s area = " << circle.area() << endl;

    EX21::Sphere sphere;
    cout << sphere.shape_name();
    sphere.resize_by_percentage(2.f);
    cout << "'s volume = " << sphere.volume() << endl;

    EX21::Cone cone;
    cout << cone.shape_name();
    cone.resize_by_percentage(2.f);
    cout << "'s volume = " << cone.volume() << endl;

    cout << "\n===== ex26 =====" << endl;

    {
        EX26::Quote quote_26;
        EX26::Quote quote_26_p("0-201-78345-X", 23.8);
        EX26::Quote quote_26_cp(quote_26_p);
        EX26::Quote quote_26_mv(std::move(quote_26_p));

        cout << "------ISBN: price------" << endl;
        cout << quote_26.isbn() << ": " << quote_26.net_price(3) << endl;
        cout << quote_26_cp.isbn() << ": " << quote_26_cp.net_price(3) << endl;
        cout << quote_26_mv.isbn() << ": " << quote_26_mv.net_price(3) << endl;
        cout << "-----------------------" << endl;

        EX26::Bulk_quote bulk_26;
        EX26::Bulk_quote bulk_26_p("0-201-78345-X", 23.8, 3, 0.5);
        EX26::Bulk_quote bulk_26_cp(bulk_26_p);
        EX26::Bulk_quote bulk_26_mv(std::move(bulk_26_p));

        cout << "------ISBN: price------" << endl;
        cout << bulk_26.isbn() << ": " << bulk_26.net_price(3) << endl;
        cout << bulk_26_cp.isbn() << ": " << bulk_26_cp.net_price(3) << endl;
        cout << bulk_26_mv.isbn() << ": " << bulk_26_mv.net_price(3) << endl;
        cout << "-----------------------" << endl;
    }

    cout << "\n===== ex27 =====" << endl;
    EX27::Bulk_quote bulk_quote_27("0-201-82470-1", 50, 5, .19);
    EX03::print_total(std::cout, bulk_quote_15, 6);

    cout << "\n===== ex30 =====" << endl;
    EX30::Basket bsk;

    for (size_t i = 0; i != 10; ++i) {
        bsk.add_item(EX30::Bulk_quote("Bible", 20.5, 5, 0.2));
        bsk.add_item(EX30::Bulk_quote("CppPrimer", 30.5, 10, 0.5));
        bsk.add_item(EX30::Quote("CLRS", 40.5));
    }

    bsk.total_receipt(std::cout);
}
