xof 0303txt 0032

Frame Root {
  FrameTransformMatrix {
     1.000000, 0.000000, 0.000000, 0.000000,
     0.000000,-0.000000, 1.000000, 0.000000,
     0.000000, 1.000000, 0.000000, 0.000000,
     0.000000, 0.000000, 0.000000, 1.000000;;
  }
  Frame BenchCollision {
    FrameTransformMatrix {
       0.723846, 0.000000, 0.000000, 0.000000,
       0.000000, 0.723846, 0.000000, 0.000000,
       0.000000, 0.000000, 0.723846, 0.000000,
       0.000000, 0.000000, 0.000000, 1.000000;;
    }
    Mesh { // BenchCollision mesh
      14;
      -7.592554;-1.301784;-0.511227;,
      -7.592554;-2.600585; 9.066132;,
      -7.592554; 2.860894;-0.511227;,
       7.337138;-1.301784;-0.511227;,
       7.337138;-2.600585; 9.066132;,
       7.337138; 2.860894;-0.511227;,
      -7.592554; 2.860894; 4.003262;,
      -7.592554;-0.886980; 9.066132;,
      -7.592554; 0.355755; 4.033991;,
       7.337138; 2.860894; 3.966382;,
       7.337138; 0.763429; 3.971942;,
       7.337138;-0.957387; 9.066132;,
      -7.592554;-1.640865; 4.533066;,
       7.337138;-1.640865; 4.533066;;
      11;
      7;2,6,8,7,1,12,0;,
      4;5,9,6,2;,
      4;8,10,11,7;,
      4;0,12,13,3;,
      4;0,3,5,2;,
      4;6,9,10,8;,
      4;4,1,7,11;,
      4;1,4,13,12;,
      3;11,13,4;,
      3;10,13,11;,
      5;3,13,10,9,5;;
      MeshNormals { // BenchCollision normals
        11;
        -1.000000; 0.000000; 0.000000;,
         0.000000; 1.000000; 0.000000;,
        -0.010256; 0.959693; 0.280862;,
         0.000000;-0.997748;-0.067069;,
         0.000000; 0.000000;-1.000000;,
         0.003205; 0.007884; 0.999964;,
         0.000000;-0.000000; 1.000000;,
         0.000000;-0.978315;-0.207124;,
         1.000000; 0.000000; 0.000000;,
         1.000000; 0.000000;-0.000000;,
         1.000000; 0.000000; 0.000000;;
        11;
        7;0,0,0,0,0,0,0;,
        4;1,1,1,1;,
        4;2,2,2,2;,
        4;3,3,3,3;,
        4;4,4,4,4;,
        4;5,5,5,5;,
        4;6,6,6,6;,
        4;7,7,7,7;,
        3;8,8,8;,
        3;9,9,9;,
        5;10,10,10,10,10;;
      } // End of BenchCollision normals
      MeshMaterialList { // BenchCollision material list
        1;
        11;
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0;
        Material mat2 {
           0.640000; 0.640000; 0.640000; 1.000000;;
           96.078431;
           0.500000; 0.500000; 0.500000;;
           0.000000; 0.000000; 0.000000;;
        }
      } // End of BenchCollision material list
    } // End of BenchCollision mesh
  } // End of BenchCollision
} // End of Root
