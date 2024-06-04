import os
import re

IGNORE_LIST = [
  # Cause people can't type
  ".gitkeep",
  ".gitpeek",
  ",gitpeek",
  "gitkeep",
  
  # Common files we allow 
  ".gitignore",
  "CMakeLists.txt",
  "resource"

  # Ignored by git
  "build",
  ".cache",
  ".DS_Store"
]

TASK_REGEX = re.compile("^Task_[0-9_]+$")
LAB_REGEX = re.compile("^LabWork_[1-9]$")
NAME_REGEX = re.compile("^[А-Я][а-яё]+ [A-Я]. ?[A-Я].$")

def check_labwork(labwork_folder):
  err = ""
  for f in os.listdir(labwork_folder):
    if f in IGNORE_LIST: continue
    
    if TASK_REGEX.match(f) is None:
      err += f"Ошибка в {labwork_folder}: Неправильно названа папка таски: {f}\n"
  return err

def check_coursework(coursework_folder):
  err = ""
  readme_found = False
  for f in os.listdir(coursework_folder):
    if f in IGNORE_LIST: continue
    if f == "README.md":
      readme_found = True

  if not readme_found:
    err += f"{coursework_folder}: В курсовой работе не найден README.md"
  return err

def check_person(person_folder):
  err = ""
  for f in os.listdir(person_folder):
    if f in IGNORE_LIST: continue
    
    if f == "Курсовая работа": 
      err += check_coursework(person_folder + "/" + f)
      continue

    if LAB_REGEX.match(f) is None:
      return f"Ошибка в {person_folder}: Неправильно названа папка лабы: " + f
    
    labres = check_labwork(person_folder + "/" + f)
    err += labres

  return err

def check_group(group_folder):
  errors = ""
  for p in os.listdir(group_folder):
    fp = group_folder + "/" + p
    res = check_person(fp)
    if NAME_REGEX.match(p) is None:
      res += f"Ошибка в {group_folder}: Неправильно названа папка студента: {p}\n"
    if len(res) != 0:
      errors += res
  return errors

errors = ""
for i in ["353501", "353502", "353503", "353504", "353505"]:
  errors += check_group(i)


print(errors)

if "GITHUB_STEP_SUMMARY" in os.environ:
  with open(os.environ["GITHUB_STEP_SUMMARY"], "w") as f:
    if len(errors) == 0:
      f.write("# Ошибок в иерархии не найдено\n")
    else:
      f.write("# Ошибки в иерархии\n\n")
      f.write("* " + errors.replace("\n", "\n* ")[:-2])

if len(errors) != 0:
  exit(1)