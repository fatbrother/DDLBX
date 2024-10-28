import os
import subprocess
import unittest

class TestCompileExamples(unittest.TestCase):
    EXAMPLES_DIR = "../docs/examples/"
    OUTPUT_DIR = "./output/"
    DDLBX_SCRIPT = "./ddlbx.sh"
    TEST_CASES_DIR = "./test/cases/"

    @classmethod
    def setUpClass(cls):
        if not os.path.exists(cls.OUTPUT_DIR):
            os.makedirs(cls.OUTPUT_DIR)
        else:
            for file in os.listdir(cls.OUTPUT_DIR):
                os.remove(os.path.join(cls.OUTPUT_DIR, file))

    def test_compile_examples(self):
        is_test_passed = True
        for example_file in os.listdir(self.EXAMPLES_DIR):
            example_file_path = os.path.join(self.EXAMPLES_DIR, example_file)
            output_file_path = os.path.join(self.OUTPUT_DIR, example_file.replace(".ddlbx", ".out"))

            print(f"Run Cmd: {self.DDLBX_SCRIPT} -i {example_file_path} -o {output_file_path}")
            subprocess.run([self.DDLBX_SCRIPT, "-i", example_file_path, "-o", output_file_path])

            if not os.path.exists(output_file_path):
                is_test_passed = False
                print(f"Output file {output_file_path} does not exist")

        self.assertTrue(is_test_passed)

        is_test_passed = True
        for example_file in os.listdir(self.EXAMPLES_DIR):
            example_file_path = os.path.join(self.EXAMPLES_DIR, example_file)
            output_file_path = os.path.join(self.OUTPUT_DIR, example_file.replace(".ddlbx", ".out"))

            print(f"Run Cmd: {output_file_path}")
            try:
                subprocess.run([output_file_path])
            except subprocess.CalledProcessError as e:
                is_test_passed = False
                print(f"Output file {output_file_path} failed to run")
                print(e)

        self.assertTrue(is_test_passed)

    def test_compile_and_check_output(self):
        test_cases = {
            "test1.ddlbx": {
                "stdin": "",
                "stdout": "Hello, World!",
            }
        }

        for test_file in test_cases.keys():
            test_file_path = os.path.join(self.TEST_CASES_DIR, test_file)
            output_file_path = os.path.join(self.OUTPUT_DIR, test_file.replace(".ddlbx", ".out"))

            print(f"Run Cmd: {self.DDLBX_SCRIPT} -i {test_file_path} -o {output_file_path}")
            subprocess.run([self.DDLBX_SCRIPT, "-i", test_file_path, "-o", output_file_path])

            if not os.path.exists(output_file_path):
                print(f"Output file {output_file_path} does not exist")
                self.assertTrue(False)

            print(f"Run Cmd: {output_file_path}")
            try:
                process = subprocess.run([output_file_path], input=test_cases[test_file]["stdin"], text=True, capture_output=True)
                self.assertEqual(process.stdout.strip(), test_cases[test_file]["stdout"])
            except subprocess.CalledProcessError as e:
                print(f"Output file {output_file_path} failed to run")
                print(e)
                self.assertTrue(False)


if __name__ == "__main__":
    unittest.main()