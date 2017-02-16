/**
* @ProgramName: Program-2
* @Author: Ricardo Rodriguez
* @Description:
*     This program reads in images stored as rgb values in a space delimited file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 15 02 2017
*/
#include<iostream>
#include<fstream>
#include<math.h>

//Structure to hold an rgb value
struct rgb {
	int r;
	int g;
	int b;
};

using namespace std;

class ImageManip {
private:
	rgb** image;
	int width;
	int height;
	ifstream infile;
	ofstream ofile;
	string ifile_name;
	string ofile_name;

	/**
	* @FunctionName: readFile
	* @Description:
	*     reads in the data from a file and stores it in the 2d array image
	* @Returns:
	*    void
	*/
	void readFile() {
		infile.open("bot.txt");
		
		infile >> width >> height;   //Read in width and height from top of input file
									 //We need this so we can make the array the right 
									 //size. After we get these two values, we can
									 //now allocate memory for our 2D array.

		image = new rgb*[height];    //This array points to every row

		for (int i = 0; i<height; i++) {
			image[i] = new rgb[width]; //Now allocate each row of rgb's
		}

		//Read the color data in from our txt file
		for (int i = 0; i<height; i++) {
			for (int j = 0; j<width; j++) {
				infile >> image[i][j].r >> image[i][j].g >> image[i][j].b;
			}
		}
		infile.close();
	}

	/**
	* @FunctionName: readFile
	* @Description:
	*     writes data from the 2d array image to a file
	* @Returns:
	*    void
	*/
	void writeFile() {
	//	ofstream ofile;
		ofile.open("bot2.txt");

		//Write out our color data to a new file
		ofile << width << " " << height << endl;
		for (int i = 0; i<height; i++) {
			for (int j = 0; j<width; j++) {
				ofile << image[i][j].r << " " << image[i][j].g << " " << image[i][j].b << " ";
			}
			ofile << endl;
		}
		ofile.close();
	}

public:
	ImageManip() {
		readFile();
	}

	/**
	* @FunctionName: flipVert
	* @Description:
	*     Loops through a 2D array and flips each rows to the opposite side.
	* @Returns:
	*    void
	*/
	void flipVert() {
		
		rgb temp;

		for (int i = 0; i < (height / 2); i++) {
			for (int j = 0; j < width; j++) {
				temp = image[i][j];
				image[i][j] = image[height - i - 1][j];
				image[height - i - 1][j] = temp;
			}
		}
		writeFile();
	}

	/**
	* @FunctionName: flipHorz
	* @Description:
	*     Loops through a 2D array and flips each column to the other side.
	* @Returns:
	*    void
	*/
	void flipHorz() {
		
		rgb temp;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < (width / 2); j++) {
				temp = image[i][j];
				image[i][j] = image[i][width - j - 1];
				image[i][width - j - 1] = temp;
			}
		}
		writeFile();
	}

	/**
	* @FunctionName: grayScale
	* @Description:
	*     Loops through a 2D array and turns every RGB value into its grayscale equivalent.
	* @Returns:
	*    void
	*/
	void grayScale() {
		
		float gray;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {

				gray = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;

				image[i][j].r = gray;
				image[i][j].g = gray;
				image[i][j].b = gray;
			}
		}
		writeFile();
	}
	~ImageManip() {
	}
};

int main() {
	ImageManip Image;

	//We could make any changes we want to the color image here
	Image.grayScale();
	Image.flipVert();
	Image.flipHorz();

	return 0;
}
