#include "ch15.h"
using namespace ch15;

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

    EX20::Pub_Derv d1;
    EX20::Priv_Derv d2;
    EX20::Prot_Derv d3;

    EX20::Derived_from_Public dd1;
    EX20::Derived_from_Private dd2;
    EX20::Derived_from_Protected dd3;

    {
        EX20::Base *p = &d1;
        // p = &d2; // error: inaccessible
        // p = &d3; // error: inaccessible
        p = &dd1;
        // p = &dd2; // error: inaccessible
        // p = &dd3; // error: inaccessible
    }

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
}
