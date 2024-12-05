#include "main.h"
#include "MDIParentForm.h"

using namespace project;  // Use the correct namespace of your project

[STAThread]
int main(array<System::String^>^ args) {
    // Enable visual styles and set compatible text rendering
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Create and run the MDIParentForm as the main form
    MDIParentForm^ mdiParent = gcnew MDIParentForm();
    Application::Run(mdiParent);  // Run the application with the MDI parent form

    return 0;
}
  