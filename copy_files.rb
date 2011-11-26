require 'rubygems'
require 'fileutils'

def create_folder(path)
  Dir::mkdir(path) unless File.directory? path
end

projects = [
  {
    :project_line1 => "Conditions",
    :group_line1 => "Anna Pinkas, Genevieve Hoffman,", 
    :group_line2 => "and Douglas Thistlethwaite"
  },
  {
    :project_line1 => "Beautiful Milka",
    :group_line1 => "Miguel Bermudez and Margaret McKenna"
  },
  {
    :project_line1 => "Stopover on",
    :project_line2 => "a Quiet Street",
    :group_line1 => "Kate Watson, Diana Huang,",
    :group_line2 => "and Emily Webster" 
  }
]

# delete folder if it's there
#FileUtils.rm_r "export" if File.directory? "export"

# create export folder
create_folder("export")

projects.each do |project|
  
  # create all the folders from project names
  folder_name = project[:project_line1]
  folder_name += "_" + project[:project_line2] unless project[:project_line2].nil?
  folder_name.downcase!.gsub!(" ", "_")
  create_folder("export/#{folder_name}")
  create_folder("export/#{folder_name}/L")
  create_folder("export/#{folder_name}/M")
  create_folder("export/#{folder_name}/R")
  
  # delete title apps if exist
  FileUtils.rm_r("export/#{folder_name}/L/titles.app") if File.directory? "export/#{folder_name}/L/titles.app"
  FileUtils.rm_r("export/#{folder_name}/M/titles.app") if File.directory? "export/#{folder_name}/M/titles.app"
  FileUtils.rm_r("export/#{folder_name}/R/titles.app") if File.directory? "export/#{folder_name}/R/titles.app"
  
  # move app into folders
  FileUtils.cp_r("bin/emptyExampleDebug.app", "export/#{folder_name}/L/titles.app")
  FileUtils.cp_r("bin/emptyExampleDebug.app", "export/#{folder_name}/M/titles.app")
  FileUtils.cp_r("bin/emptyExampleDebug.app", "export/#{folder_name}/R/titles.app")
  
  # rename to "titles"
  # File.rename("export/#{folder_name}/L/emptyExampleDebug.app", "export/#{folder_name}/L/titles.app")
  # File.rename("export/#{folder_name}/M/emptyExampleDebug.app", "export/#{folder_name}/M/titles.app")
  # File.rename("export/#{folder_name}/R/emptyExampleDebug.app", "export/#{folder_name}/R/titles.app")
end

# export xml into each folder
  # overwrite if file exists, if not create it
