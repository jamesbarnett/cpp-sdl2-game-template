require 'rake'

task :cmake do
  desc "Runs the cmake command"
  Dir.mkdir "build" if !File.exists? "build"
  Dir.chdir "build" do
    puts `cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../`
  end
end

task :make do
  desc "Runs the make command after cmake is run"
  make
end


task :clean do
  desc "Removes the build directory"
  `rm -rf build`
  Dir.mkdir("build")
end

task :build do
  desc "Builds everything"
  Dir.mkdir "build" if !File.exists? "build"
  Rake::Task["cmake"].execute
  Rake::Task["make"].execute
end

task :rebuild do
  desc "Rebuilds everything"
  Rake::Task["clean"].execute
  Rake::Task["cmake"].execute
  Rake::Task["make"].execute
end

task :run do
  puts `./build/sdl2-test`
end

task :rebuild_and_run do
  desc "Rebuilds everything and runs the executable"
  Rake::Task["rebuild"].execute
  Rake::Task["run"].execute
end

def cmake
  puts "calling the cmake command"
  Dir.mkdir "build" if !File.exists? "build"
  Dir.chdir "build" do
  end
end

def make
  puts "calling the make command"
  Dir.chdir "build" do
    puts `make`
  end
end

