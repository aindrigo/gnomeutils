import os
from conan import ConanFile
from conan.tools.cmake import CMake
from conan.tools.files import copy

class GnomeUtilsConan(ConanFile):
    name = "gnomeutils"
    version = "1.0.0"

    settings = ("os", "compiler", "build_type", "arch")
    generators = ("CMakeToolchain", "CMakeDeps")

    def export_sources(self):
        copy(self, "CMakeLists.txt", self.recipe_folder, self.export_sources_folder)
        copy(self, "src/*.cpp", self.recipe_folder, self.export_sources_folder)
        copy(self, "include/*", self.recipe_folder, self.export_sources_folder)

    def package(self):
        copy(self, pattern="*", src=os.path.join(self.source_folder, "include"), dst=os.path.join(self.package_folder, "include"))
        copy(self, pattern="*.cpp", src=os.path.join(self.source_folder, "src"), dst=os.path.join(self.package_folder, "src"))
        copy(self, pattern="*.a", src=self.build_folder, dst=os.path.join(self.package_folder, "lib"), keep_path=False)
        copy(self, "CMakeLists.txt", src=self.source_folder, dst=self.package_folder, keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["gnomeutils"]
        self.cpp_info.set_property("cmake_target_name", "gnomeutils::gnomeutils")
    def layout(self):
        self.folders.source = "."
        self.folders.build = os.path.join("build", str(self.settings.build_type))
        self.folders.generators = os.path.join(self.folders.build, "generators")

        self.cpp.package.libs = ["gnomeutils"]
        self.cpp.package.includedirs = ["include"]
        self.cpp.package.libdirs = ["lib"]

        self.cpp.source.includedirs = ["include"]
        self.cpp.build.libdirs = ["."]

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()