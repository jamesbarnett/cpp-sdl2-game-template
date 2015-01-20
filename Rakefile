require 'rake'

task :cmake do
  desc "Runs the cmake command"
  Dir.chdir "build" do
    puts `cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../`
  end

  Dir.chdir ".."
end

task :make do
  desc "Runs the make command after cmake is run"
  Dir.chdir "build" do
    puts `make`
  end

  Dir.chdir ".."
end

task :clean do
  desc "Removes the build directory"
  `rm -rf build`
  Dir.mkdir("build")
end

task :build do
  desc "Builds everything"
  Dir.mkdir "build" if !File.exists "build"
  Rake::Task["cmake"].execute
  Rake::Task["make"].execute
end

task :rebuild do
  desc "Rebuilds everything"
  Rake::Task["clean"].execute
  Rake::Task["cmake"].execute
  Rake::Task["make"].execute
end
