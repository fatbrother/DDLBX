import os
import subprocess
import unittest

class TestDDLBXIntegration(unittest.TestCase):
    EXAMPLES_DIR = "../docs/examples/"
    OUTPUT_DIR = "./output/"
    DDLBX_SCRIPT = "./ddlbx.sh"

    @classmethod
    def setUpClass(cls):
        if not os.path.exists(cls.OUTPUT_DIR):
            os.makedirs(cls.OUTPUT_DIR)
        else:
            for file in os.listdir(cls.OUTPUT_DIR):
                os.remove(os.path.join(cls.OUTPUT_DIR, file))

    def test_compile_examples(self):
        # for each example file in the examples directory
        # ./ddlbx.sh -i {example_file} -o ./output/{example_file}.out
        is_test_passed = True
        for example_file in os.listdir(self.EXAMPLES_DIR):
            example_file_path = os.path.join(self.EXAMPLES_DIR, example_file)
            output_file_path = os.path.join(self.OUTPUT_DIR, example_file.replace(".ddlbx", ".out"))

            print(f"Run Cmd: {self.DDLBX_SCRIPT} -i {example_file_path} -o {output_file_path}")
            subprocess.run([self.DDLBX_SCRIPT, "-i", example_file_path, "-o", output_file_path])

            # check if the output file exists
            if not os.path.exists(output_file_path):
                is_test_passed = False
                print(f"Output file {output_file_path} does not exist")

        self.assertTrue(is_test_passed)


if __name__ == "__main__":
    unittest.main()