class FileSystem:
    def __init__(self):
        self.current_directory = "/"
        self.directory_structure = {"/": {}}

    def change_directory(self, path):
        if path[0] != "/":
            path = f"{self.current_directory}/{path}"

        parts = path.split("/")
        current = self.directory_structure

        for part in parts[1:]:
            if part in current:
                current = current[part]
            else:
                print(f"Error: Directory '{part}' not found.")
                return

        self.current_directory = path

    def create_directory(self, name):
        path = f"{self.current_directory}/{name}"

        if path in self.directory_structure:
            print("Error: Directory already exists.")
        else:
            self.directory_structure[path] = {}
            print(f"Directory '{name}' created at {path}.")

    def delete_directory(self, name):
        path = f"{self.current_directory}/{name}"

        if path == "/":
            print("Error: Cannot delete the root directory.")
        elif path in self.directory_structure:
            del self.directory_structure[path]
            print(f"Directory '{name}' deleted from {self.current_directory}.")
        else:
            print(f"Error: Directory '{name}' not found.")

    def print_directory_structure(self, current=None, indent=""):
        if current is None:
            current = self.directory_structure

        for key, value in current.items():
            print(indent + f"- {key}")
            if value:
                self.print_directory_structure(value, indent + "  ")

if __name__ == "__main__":
    fs = FileSystem()

    fs.create_directory("documents")
    fs.create_directory("pictures")
    fs.change_directory("documents")
    fs.create_directory("python")
    fs.change_directory("..")
    fs.print_directory_structure()

    fs.delete_directory("documents")
    fs.print_directory_structure()
