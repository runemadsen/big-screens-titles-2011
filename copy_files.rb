require 'rubygems'
require 'fileutils'
require 'xmlsimple'

def create_folder(path)
  Dir::mkdir(path) unless File.directory? path
end

def delete_folder(path)
  FileUtils.rm_r(path) if File.directory? path
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
  delete_folder("export/#{folder_name}/L/titles.app")
  delete_folder("export/#{folder_name}/M/titles.app")
  delete_folder("export/#{folder_name}/R/titles.app")
  
  # move app into folders
  FileUtils.cp_r("bin/emptyExampleDebug.app", "export/#{folder_name}/L/titles.app")
  FileUtils.cp_r("bin/emptyExampleDebug.app", "export/#{folder_name}/M/titles.app")
  FileUtils.cp_r("bin/emptyExampleDebug.app", "export/#{folder_name}/R/titles.app")
  
  # create xml hashes
  left_hash = project.merge({ :scale => 1.4, :xpos => 1140, :ypos => 400, :video_name => folder_name + "_L.mov" })
  middle_hash = project.merge({ :scale => 1.4, :xpos => 720, :ypos => 400, :video_name => folder_name + "_M.mov" })
  right_hash = project.merge({ :scale => 1.4, :xpos => 120, :ypos => 400, :video_name => folder_name + "_R.mov" })
  
  # delete old xml files
  delete_folder("export/#{folder_name}/L/settings.xml")
  delete_folder("export/#{folder_name}/M/settings.xml")
  delete_folder("export/#{folder_name}/R/settings.xml")
  
  # create xml file objects
  left_xml = File.new("export/#{folder_name}/L/settings.xml", "w")
  middle_xml = File.new("export/#{folder_name}/M/settings.xml", "w")
  right_xml = File.new("export/#{folder_name}/R/settings.xml", "w")
  
  # write to the files
  left_xml.puts XmlSimple.xml_out(left_hash, 'NoAttr' => true, 'RootName' => "root")
  middle_xml.puts XmlSimple.xml_out(middle_hash, 'NoAttr' => true, 'RootName' => "root")
  right_xml.puts XmlSimple.xml_out(right_hash, 'NoAttr' => true, 'RootName' => "root")
end
