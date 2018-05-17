#include <boost/python.hpp>

#include <moveit/python/python_tools/conversions.h>
#include <moveit/python/task_constructor/properties.h>
#include <moveit/task_constructor/stage.h>
#include <moveit/task_constructor/task.h>

namespace bp = boost::python;
using namespace moveit::task_constructor;

namespace moveit {
namespace python {

void export_properties();
void export_solvers();

namespace {

void Task_add(Task& self, std::auto_ptr<Stage> stage) {
	return self.add(std::unique_ptr<Stage>{stage.release()});
}
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(Task_enableIntrospection_overloads, Task::enableIntrospection, 0, 1)

}

void export_core()
{
	PropertyMap& (Stage::*Stage_getPropertyMap)() = &Stage::properties;  // resolve method ambiguity
	properties::class_<Stage, std::auto_ptr<Stage>, boost::noncopyable>("Stage", bp::no_init)
	      // expose name as writeable property, returned string reference will be copied
	      .property<double>("timeout")
	      .add_property("name",
	                    bp::make_function(&Stage::name, bp::return_value_policy<bp::copy_const_reference>()),
	                    &Stage::setName)
	      // read-only access to properties, reference returned directly as pointer
	      .add_property("properties", bp::make_function(Stage_getPropertyMap, bp::return_internal_reference<>()))
	;

	PropertyMap& (Task::*Task_getPropertyMap)() = &Task::properties;
	bp::class_<Task, boost::noncopyable>("Task", bp::init<bp::optional<const std::string& /* TODO the ContainerBase::pointer&& is currently omitted */>>())
	      .add_property("id", &Task::id)
	      .add_property("properties", bp::make_function(Task_getPropertyMap, bp::return_internal_reference<>()))

	      .def("loadRobotModel", &Task::loadRobotModel)
	      .def("enableIntrospection", &Task::enableIntrospection, Task_enableIntrospection_overloads())
	      .def("clear", &Task::clear)
	      .def("reset", &Task::reset)
	      .def("init", &Task::init)
	      .def("plan", &Task::plan)
	      .def("add", &Task_add)
	;
}

} }